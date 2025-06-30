@echo off
set /p msg="Enter commit message: "
echo.
echo Running Git commands...

git add .
git commit -m "%msg%"
git branch -M main
git push -u origin main

echo.
echo Done! Press any key to exit.
pause >nul
