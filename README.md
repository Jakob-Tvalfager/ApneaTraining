# ApneaTraining

A C program to improve CO2 tolerance for sleep apnea using breath-hold exercises adapted from freediving CO2 tables.

## Overview

This project provides a command-line tool to train CO2 tolerance, helping users breathe more steadily to reduce sleep apnea symptoms. It includes two training modes:
- **Type A**: Fixed breath-hold duration with decreasing rest periods.
- **Type B**: Increasing breath-hold durations with fixed rest periods.

The program measures a "Relaxed Pause" (breath-hold time after exhale) and saves it to `relaxedPauseData.txt` for progress tracking.

## Screenshots

![Delete option & Type A Training](https://raw.githubusercontent.com/Jakob-Tvalfager/ApneaTraining/main/images/DemoDeleteAndTypeA.webp)
![Persistent storage & Type B training](https://raw.githubusercontent.com/Jakob-Tvalfager/ApneaTraining/main/images/DemoPersistentStorageAndTypeB.webp)

## Usage

### Running Binaries
Precompiled binaries are provided in the `bin` folder:
- Linux: `apnea_linux`
- Windows: `apnea.exe`

Download the appropriate binary and run:
- Linux:
  ```bash
  chmod +x bin/apnea_linux
  ./bin/apnea_linux
  ```
- Windows:
  ```cmd
  bin\apnea.exe
  ```

### Compilation Instructions

#### Linux
1. Install GCC:
   ```bash
   sudo apt-get install gcc
   ```
2. Compile:
   ```bash
   gcc -Wall -std=c11 apneaTraining.c -o apnea
   ```
3. Run:
   ```bash
   ./apnea
   ```

#### Windows
1. Install MinGW (e.g., via MSYS2):
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```
2. Compile:
   ```cmd
   gcc -Wall -std=c11 apneaTraining.c -o apnea.exe
   ```
3. Run:
   ```cmd
   apnea.exe
   ```

### Training Modes
Choose a mode:
- Press `1` for Type A.
- Press `2` for Type B.
- Press Enter for the default (last used mode).

## Requirements

- **Linux**: GCC, POSIX-compliant system (for `unistd.h`, `sleep`)
- **Windows**: MinGW or compatible C compiler
- **Binaries**: No additional dependencies

## Notes

- Ensure WebP images are in the `images` folder or update paths in this README.
- The program creates and reads from `relaxedPauseData.txt` in the working directory.
- Use `git rm -r --cached <file>` to remove accidental file commits (e.g., PDFs).
- Binaries are provided for convenience; compile from source for custom modifications.
