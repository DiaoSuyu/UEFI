fs0:
load E1000\E3522X2.EFI            # Loads the E1000 network driver, supporting Intel 10/100/1000 Ethernet controllers (E3522X2 is a specific model of the network card)
load NetworkPkg\SnpDxe.efi        # Loads the SNP (Simple Network Protocol) driver, enabling network functionality support
load NetworkPkg\MnpDxe.efi        # Loads the MNP (Managed Network Protocol) driver, providing higher-level network functionality
load NetworkPkg\ArpDxe.efi        # Loads the ARP (Address Resolution Protocol) driver, used to resolve mappings between IP and MAC addresses
load NetworkPkg\Ip4Dxe.efi        # Loads the IP4 (Internet Protocol version 4) driver, providing support for IPv4 communication
load NetworkPkg\VlanConfigDxe.efi # Loads the VLAN configuration driver, supporting the configuration of Virtual Local Area Networks (VLANs)
load NetworkPkg\Udp4Dxe.efi       # Loads the UDP4 (User Datagram Protocol for IPv4) driver, providing support for UDP communication over IPv4
load NetworkPkg\Dhcp4Dxe.efi      # Loads the DHCP4 (Dynamic Host Configuration Protocol for IPv4) driver, enabling automatic IP address assignment
load NetworkPkg\Mtftp4Dxe.efi     # Loads the TFTP (Trivial File Transfer Protocol) driver, supporting file transfers over the network
load NetworkPkg\TcpDxe.efi        # Loads the TCP (Transmission Control Protocol) driver, providing support for TCP communication
# DelayTool.efi 15                  # Delay 10s
ConnectWithTcp4.efi 192.168.77.10 8888
