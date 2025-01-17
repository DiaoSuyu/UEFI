# Git Commands

This document outlines common Git commands for **global configuration**, **submodule management**, and **other operations**.

## **Global Configuration Commands**

1. **Edit Global Git Configuration**  
   Opens the global Git configuration file for editing.

   ```bash
   git config --global --edit
   ```

2. **Disable NTFS Protection**  
   Disables the NTFS protection, which resolves issues with invalid paths when working with Git on Windows.

   ```bash
   git config --global core.protectNTFS false
   ```

3. **Configure Git Credential Storage**  
   Configures Git to store credentials (username and password) for future use to avoid entering them repeatedly.

   ```bash
   git config --global credential.helper store
   ```

4. **Set Git Mirror URL**  
   Configures Git to use a mirror URL, which can be helpful for faster access in certain regions.

   ```bash
   git config --global url."https://github.com.cnpmjs.org/".insteadOf "https://github.com/"
   ```

## **Submodule Management Commands**

1. **View Submodule Status**  
   Checks the status of all submodules in the repository.

   ```bash
   git submodule status
   ```

2. **Sync Submodules Recursively**  
   Updates all submodules recursively to ensure they are in sync with the super project's configuration.

   ```bash
   git submodule sync --recursive
   ```

3. **Initialize Submodules Recursively**  
   Initializes and updates all submodules recursively, ensuring all required submodules are available.

   ```bash
   git submodule update --init --recursive
   ```

4. **Reset All Submodules**  
   Resets all submodules to their committed state, discarding any local changes.

   ```bash
   git submodule foreach --recursive git reset --hard
   ```

5. **Clean Uncommitted Changes in Submodules**  
   Discards all uncommitted changes in submodules.

   ```bash
   git submodule foreach --recursive git checkout .
   ```

6. **Remove Untracked Files from Submodules**  
   Cleans all untracked files in submodules (e.g., generated files that are not tracked by Git).

   ```bash
   git submodule foreach --recursive git clean -fdx
   ```

7. **Add a New Submodule**  
   Adds a new submodule to the project and forces it to be added even if there are existing submodule configurations.

   ```bash
   git submodule add --force https://XXX XXX
   ```

8. **Remove a Submodule Directory**  
   Removes an old or unwanted submodule directory from the project.

   ```bash
   rm -rf Tools/efiXplorer
   ```

9. **Update Submodules Recursively**  
   Update all submodules to the latest commit of the remote repository.

   ```bash
   git submodule update --recursive --remote
   ```

## **Other Useful Git Commands**

1. **Download a File Using Git Bash (curl)**  
   Uses `curl` to download a file directly from a URL via Git Bash.

   ```bash
   curl -O https://i-blog.csdnimg.cn/blog_migrate/d2eb3272b3f263a94aa4f04e48466116.png
   ```

2. **Clean Up Stale Remote Tracking Branches**  
   If the remote branches no longer exist but are still tracked locally, you can clean them up by running:

   ```bash
   git fetch -p
   ```

   This command fetches the latest updates from the remote repository and prunes the references to the remote branches that have been deleted.

3. **Manually Remove Remote Tracking Branches**  
   If the previous command didn't clean up the obsolete branches, you can manually delete them by running, These commands will remove the local tracking branches for `origin/windows`:

   ```bash
   git branch -dr origin/windows
   ```
