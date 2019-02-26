@echo off
set platform=%1

IF "%platform%"=="arduino"(
	echo arduino
)
IF "%platform%"=="native"(
	echo native
)