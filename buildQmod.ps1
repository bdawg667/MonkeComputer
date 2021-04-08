# Builds a .zip file for loading with BMBF
$NDKPath = Get-Content $PSScriptRoot/ndkpath.txt

$buildScript = "$NDKPath/build/ndk-build"
if (-not ($PSVersionTable.PSEdition -eq "Core")) {
    $buildScript += ".cmd"
}

& $buildScript NDK_PROJECT_PATH=$PSScriptRoot APP_BUILD_SCRIPT=$PSScriptRoot/Android.mk NDK_APPLICATION_MK=$PSScriptRoot/Application.mk -j 4
Compress-Archive -Path  "./libs/arm64-v8a/libbeatsaber-hook_1_2_6.so",`
                        "./libs/arm64-v8a/libcustom-types.so",`
                        "./libs/arm64-v8a/libmonkecomputer.so",`
                        "./libs/arm64-v8a/libquest-cosmetic-loader_0_1_2.so",`
                        "./libs/arm64-v8a/libzip.so",`
                        "./ExtraFiles/Monitor.package",`
                        "./mod.json" -DestinationPath "./MonkeComputer.zip" -Update

& copy-item -Force "./MonkeComputer.zip" "./MonkeComputer.qmod"