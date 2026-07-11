@echo off
setlocal

set VCPKG=C:\dev\vcpkg\scripts\buildsystems\vcpkg.cmake

echo ==========================
echo Configuring FeedEngine
echo ==========================

cmake -B build ^
-DCMAKE_TOOLCHAIN_FILE=%VCPKG% ^
-DVCPKG_TARGET_TRIPLET=x64-windows-static ^
-DCMAKE_BUILD_TYPE=Release


if %errorlevel% neq 0 (
    echo.
    echo CMake configure failed!
    pause
    exit /b 1
)


echo.
echo ==========================
echo Building FeedEngine
echo ==========================

cmake --build build --config Release


if %errorlevel% neq 0 (
    echo.
    echo Build failed!
    pause
    exit /b 1
)


echo.
echo ==========================
echo Installing SDK
echo ==========================

cmake --install build --config Release --prefix SDK


if %errorlevel% neq 0 (
    echo.
    echo Install failed!
    pause
    exit /b 1
)


echo.
echo ==========================
echo FeedEngine build complete!
echo SDK created in:
echo %CD%\SDK
echo ==========================

pause