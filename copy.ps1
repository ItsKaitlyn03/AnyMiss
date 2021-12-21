& $PSScriptRoot/build.ps1
if ($?) {
    adb push obj/local/arm64-v8a/libanymiss.so /sdcard/Android/data/com.beatgames.beatsaber/files/mods/libanymiss.so
    if ($?) {
        & $PSScriptRoot/restart-game.ps1
        if ($args[0] -eq "--log") {
            & $PSScriptRoot/start-logging.ps1
        }
    }
}
