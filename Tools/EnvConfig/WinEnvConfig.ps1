# Set log file path
$logFile = "C:\uefi-work-space\Tools\EnvConfig\WinEnvConfig.log"

# Clear log file
"Clearing log file..." | Out-File -FilePath $logFile -Encoding UTF8

# Check and set execution policy to RemoteSigned if necessary
$currentExecutionPolicy = Get-ExecutionPolicy
if ($currentExecutionPolicy -ne 'RemoteSigned') {
    "Changing execution policy to RemoteSigned..." | Out-File -Append -FilePath $logFile -Encoding UTF8
    Set-ExecutionPolicy RemoteSigned -Scope CurrentUser -Force
    "Execution policy changed to RemoteSigned." | Out-File -Append -FilePath $logFile -Encoding UTF8
} else {
    "Execution policy is already set to RemoteSigned." | Out-File -Append -FilePath $logFile -Encoding UTF8
}

# Set environment variables and log the action
# "Setting environment variables" | Out-File -Append -FilePath $logFile -Encoding UTF8
# [System.Environment]::SetEnvironmentVariable("CYGWIN_HOME", "C:\uefi-work-space\Tools\BuildTools\Cygwin64", [System.EnvironmentVariableTarget]::Machine)
# [System.Environment]::SetEnvironmentVariable("CLANG_BIN", "C:\uefi-work-space\Tools\BuildTools\Cygwin64\bin", [System.EnvironmentVariableTarget]::Machine)
# [System.Environment]::SetEnvironmentVariable("NASM_PREFIX", "C:\uefi-work-space\Tools\BuildTools\NASM\", [System.EnvironmentVariableTarget]::Machine)
# [System.Environment]::SetEnvironmentVariable("PYTHON_HOME", "C:\uefi-work-space\Tools\BuildTools\Python\Python313", [System.EnvironmentVariableTarget]::Machine)
# [System.Environment]::SetEnvironmentVariable("PYTHON_COMMAND", "C:\uefi-work-space\Tools\BuildTools\Python\Python313\python.exe", [System.EnvironmentVariableTarget]::Machine)
# [System.Environment]::SetEnvironmentVariable("IASL_PREFIX", "C:\uefi-work-space\Tools\BuildTools\ASL", [System.EnvironmentVariableTarget]::Machine)

# Define paths to be added to PATH variable
$newPaths = @(
	"C:\Windows",
	"C:\Windows\system32"
    #"C:\uefi-work-space\Tools\BuildTools\ASL",
    #"C:\uefi-work-space\Tools\BuildTools\Cygwin64",
    #"C:\uefi-work-space\Tools\BuildTools\NASM"
)

# Get the current system PATH
"Getting the current system PATH..." | Out-File -Append -FilePath $logFile -Encoding UTF8
$path = [System.Environment]::GetEnvironmentVariable("PATH", [System.EnvironmentVariableTarget]::Machine)

# Log the current PATH
"Current system PATH: $path" | Out-File -Append -FilePath $logFile -Encoding UTF8

# Check and add paths
"Checking and adding paths..." | Out-File -Append -FilePath $logFile -Encoding UTF8

foreach ($newPath in $newPaths) {
    if ($path -notlike "*$newPath*") {
        # If the path is not in the current PATH, add it
        "Adding path: $newPath" | Out-File -Append -FilePath $logFile -Encoding UTF8
        $path = "$path;$newPath"
    } else {
        # If the path already exists
        "Path already exists: $newPath" | Out-File -Append -FilePath $logFile -Encoding UTF8
    }
}

# Update the system PATH
"Updated PATH: $path" | Out-File -Append -FilePath $logFile -Encoding UTF8
[System.Environment]::SetEnvironmentVariable("PATH", $path, [System.EnvironmentVariableTarget]::Machine)

# Log completion
"Environment variables have been set successfully!" | Out-File -Append -FilePath $logFile -Encoding UTF8

# Provide the log file location
"Process completed, log file has been generated at: $logFile" | Out-File -Append -FilePath $logFile -Encoding UTF8
