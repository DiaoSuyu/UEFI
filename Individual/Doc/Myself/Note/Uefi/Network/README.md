# Configuring Bridge Networking for QEMU on Ubuntu

This tutorial will guide you through setting up bridge networking for QEMU on Ubuntu, allowing your QEMU virtual machine to share the same network connection as your physical machine.

## 1. Install Necessary Tools

First, install the tools required for configuring bridge networking and User Mode Linux (UML) utilities:

```bash
sudo apt-get install bridge-utils  # Virtual bridge configuration tools
sudo apt-get install uml-utilities # UML (User-mode Linux)
```

## 2. Create and Configure the Bridge Interface

### 2.1. **Create the `br0` Bridge Interface**

You can create a new bridge interface using the `ip` command. If you already have a bridge interface, skip this step.

```bash
sudo ip link add name br0 type bridge
```

### 2.2. **Add the Physical Network Interface to the Bridge**

Assuming your physical network interface is `enp0s3`, add it to the `br0` bridge interface. This allows QEMU to share the network connection.

```bash
sudo ip link set enp0s3 master br0
```

### 2.3. **Configure the Bridge Interface (`br0`) to Get an IP Address**

- **Obtain a Dynamic IP Address:**

  Use DHCP to get an IP address:

  ```bash
  sudo dhclient br0
  ```

- **Configure a Static IP Address:**

  To set a static IP, use the following commands, assuming the static IP is `192.168.77.163`:

  ```bash
  sudo ip addr add 192.168.77.163/24 dev br0
  ```

- **Configure a `tap` Interface:**

  ```bash
  sudo ip tuntap add dev tap0 mode tap
  sudo ip link set tap0 master br0
  ```

### 2.4. **Ensure Both the Bridge and Physical Network Interface Are `UP`**

```bash
sudo ip link set br0 up
sudo ip link set enp0s3 up
sudo ip link set tap0 up
```

### 2.5. **Check the IP Configuration of the Bridge Interface**

Use the following command to check if `br0` has been assigned an IP address:

```bash
ip addr show br0
```

If the bridge is configured correctly, you should see the IP address assigned to `br0`, and the QEMU virtual machine should be able to access the same network as the physical machine.

### 2.6. **Check if the Physical Network Interface `enp0s3` Is Associated with the Bridge**

Run the following command to check if `enp0s3` is correctly added to the bridge `br0`:

```bash
ip addr show
```

You should see output similar to this:

```shell
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel master br0 state UP group default qlen 1000
    link/ether 08:00:27:39:5c:2c brd ff:ff:ff:ff:ff:ff
    inet 192.168.77.119/24 brd 192.168.77.255 scope global noprefixroute enp0s3
       valid_lft forever preferred_lft forever
    inet6 fe80::4c94:9b80:38a0:cea1/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
12: tap0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc fq_codel state DOWN group default qlen 1000
    link/ether d2:20:61:63:21:f9 brd ff:ff:ff:ff:ff:ff
14: br0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default qlen 1000
    link/ether 46:5d:c4:0f:f8:80 brd ff:ff:ff:ff:ff:ff
    inet 192.168.77.163/24 brd 192.168.77.255 scope global dynamic br0
       valid_lft 86121sec preferred_lft 86121sec
    inet6 fe80::e6aa:8ec2:3b62:2d9f/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever

```

As shown, both `br0` and `enp0s3` should have their own IP addresses, and the status should be `UP`.

Sure, here's a more detailed version of the "Verify IP Routing" section:

---

### 2.7. Verify IP Routing

After setting up the bridge and configuring your network interfaces, it's important to verify the IP routing configuration to ensure that the traffic will correctly flow through the bridge network.

#### 2.7.1 View Current Routing Table

To view the current routing table, use the following command:

```bash
ip route show
```

This command will display the routing information for your system. The expected output might look something like this:

```bash
ubuntu@ubuntu-VirtualBox:~$ ip route show
default via 192.168.77.1 dev br0 
default via 192.168.77.1 dev enp0s3 proto static metric 100 
169.254.0.0/16 dev enp0s3 scope link metric 1000 
192.168.77.0/24 dev br0 proto kernel scope link src 192.168.77.163 
192.168.77.0/24 dev enp0s3 proto kernel scope link src 192.168.77.119 metric 100
```

#### 2.7.2 Explanation of the Routing Table

- **`default via 192.168.77.1 dev br0`**: This shows the default route for all outbound traffic, which is routed through the bridge interface `br0` to the gateway `192.168.77.1`.
  
- **`default via 192.168.77.1 dev enp0s3 proto static metric 100`**: This indicates another default route but routed through the physical network interface `enp0s3`. It's using static routing, and the metric is set to 100, which is a relatively lower priority for this route.
  
- **`169.254.0.0/16 dev enp0s3 scope link metric 1000`**: This represents the link-local network, which is used when a system cannot obtain an IP address via DHCP. It's routed through `enp0s3` and has a higher metric (1000) to indicate lower priority.
  
- **`192.168.77.0/24 dev br0 proto kernel scope link src 192.168.77.163`**: This route indicates that the `br0` interface is handling the `192.168.77.0/24` subnet.
  
- **`192.168.77.0/24 dev enp0s3 proto kernel scope link src 192.168.77.119 metric 100`**: This indicates that the `enp0s3` interface is handling the same subnet but with a different IP address and lower priority.

#### 2.7.3 Adjusting the Routing Table

In some cases, after setting up a bridge, you may need to adjust the default route. For example, you may want to ensure that the default gateway (`192.168.77.1`) is routed via the bridge interface (`br0`) instead of the physical network interface (`enp0s3`).

You can achieve this by first deleting the previous default route through `enp0s3`:

```bash
sudo ip route del default via 192.168.77.1 dev enp0s3
```

This will remove the old route pointing to `enp0s3`. Afterward, add a new default route through the bridge interface (`br0`), ensuring the traffic goes through the bridge:

```bash
sudo ip route add default via 192.168.77.1 dev br0 metric 425
```

Here, we set a metric of `425` for the new default route, ensuring that it has a higher priority than other routes (lower metric values have higher priority).

#### 2.7.4 Restart Network Manager

After modifying the routes, restart the network service to ensure that all changes take effect properly:

```bash
sudo systemctl restart NetworkManager
```

#### 2.7.5 Verify Updated Routing Table

Once you've made these adjustments, check the routing table again to confirm that the default route is now correctly set to `br0`. The updated output should look like this:

```bash
ubuntu@ubuntu-VirtualBox:~$ ip route show
default via 192.168.77.1 dev br0 
default via 192.168.77.1 dev br0 proto dhcp metric 425 
169.254.0.0/16 dev enp0s3 scope link metric 1000 
192.168.77.0/24 dev br0 proto kernel scope link src 192.168.77.163 
192.168.77.0/24 dev enp0s3 proto kernel scope link src 192.168.77.119 metric 100 
192.168.77.0/24 dev br0 proto kernel scope link src 192.168.77.163 metric 425
```

- **`default via 192.168.77.1 dev br0`**: The primary default route now uses the bridge interface `br0` as the gateway.
  
- **`default via 192.168.77.1 dev br0 proto dhcp metric 425`**: This confirms the DHCP-assigned default route through the bridge with the updated metric of `425`.

By following these steps, you ensure that your system uses the bridge network as the primary route for all outbound traffic, making it share the same network as the host machine.

#### 2.7.6 Disable firewall

```bash
sudo ufw disable
```

## 3. Configure QEMU to Use Bridge Networking

Now that you've created and configured the bridge interface, configure QEMU to use it.

### **Configure the `bridge.conf` File**

```bash
cd /usr/local/etc/
sudo mkdir qemu
cd qemu
sudo vim bridge.conf
# Fill in the value and save in bridge.conf: allow br0
```

### 4. **Start the QEMU Virtual Machine Using Bridge Networking**

Use the `-netdev bridge` and `-device` options to configure the virtual machine to use bridge networking. Here's an example command:

```bash
sudo qemu-system-x86_64 \
-drive if=pflash,format=raw,file=OVMF.fd,id=BIOS-OVMF \
-drive file=fat:rw:hda-contents,format=raw,if=ide,index=0 \
-netdev bridge,id=net0,br=br0 \
-device e1000,netdev=net0 \
-cpu Penryn,+rdrand \
-debugcon file:debug.log \
-global isa-debugcon.iobase=0x402 \
-s
```

This command starts a QEMU virtual machine with the `br0` bridge network, and `e1000` is the network adapter used within the virtual machine.

### 5. Recovering Original Ubuntu Network

If you need to remove the bridge interface (`br0`), follow these additional steps:

1. **Shut Down the `tap0` Interface**

   Bring the `tap0` interface down:

   ```bash
   sudo ip link set tap0 down
   ```

2. **Delete the `tap0` Interface**

   Delete the `tap0` interface. You can use the following command:

   ```bash
   sudo ip tuntap del tap0 mode tap
   ```

   If this command shows an error, try this alternative command to delete `tap0`:

   ```bash
   sudo ip link delete tap0
   ```

3. **Shut Down the `br0` Bridge**

   Bring the `br0` interface down:

   ```bash
   sudo ip link set br0 down  # Shut down br0 bridge
   ```

4. **Delete the Bridge**

   Delete the `br0` bridge:

   ```bash
   sudo brctl delbr br0  # Delete the br0 bridge
   ```

5. **Unbind the `enp0s3` Network Interface**

   Make sure `enp0s3` is no longer associated with the bridge:

   ```bash
   sudo ip link set enp0s3 nomaster  # Unbind enp0s3 from the br0 bridge
   ```

6. **Restart Network Services**

   If the interface is still not functioning, restarting the networking service can help:

   ```bash
   sudo systemctl restart NetworkManager
   ```

7. **Obtain a New IP Address**

   After removing the bridge and unbinding the interface, try obtaining a new IP address using DHCP:

   ```bash
   sudo dhclient enp0s3
   ```

8. **Check Network Status**

   Check the status of the `enp0s3` interface to ensure it has returned to normal:

   ```bash
   ip addr show enp0s3
   ```

---

This guide now provides a complete and detailed explanation for setting up bridge networking in QEMU on Ubuntu, and also how to remove the bridge setup when no longer needed.