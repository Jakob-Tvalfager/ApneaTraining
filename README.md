# ApneaTraining

A C program to improve CO2 tolerance for sleep apnea using breath-hold exercises adapted from freediving CO2 tables.

# Why train CO2 tolerance to beat sleep apnea?

Dylan petkus said it best:

## 📹 Videos

| Demo | Description |
|------|-------------|
| [![Why CO2 tolerance](https://img.youtube.com/vi/mwYpIRgKE6M/mqdefault.jpg)](youtube.com/vi/mwYpIRgKE6M) | **Quick Overview** - Why C02 tolerance matters |
| [![CO2 tolerance test](https://img.youtube.com/vi/Q602fG-ByKU/mqdefault.jpg)](youtube.com/vi/Q602fG-ByKU) | **Concept** - Introduction to the relaxed pause concept |
| [![How a CPAP Makes Sleep Apnea Worse
through worsening CO2 tolerance](https://img.youtube.com/vi/D_7Azhtol1U/mqdefault.jpg)](youtube.com/vi/D_7Azhtol1U) |  |

Cheers to Dylan for inspiring me to make this!

## 🚀 Try It online

### GitHub Codespaces (Full Featured)
[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/jakob-Tvalfager/apneatraining)

Get a complete development environment with full terminal access.

---

If there is no compiled binary you can

Compile it, run:
```bash
gcc -o apneaTraining apneaTraining.c
./apneaTraining

## Overview

This project provides a command-line tool to train CO2 tolerance, helping users breathe more steadily to reduce sleep apnea symptoms. It includes three training modes:

### Training Modes
Type A - Fixed Breath Hold, Decreasing Rest. Short session.

Type B - Increasing Breath Hold, Fixed Rest. Short session.

Type C - Fixed Breath Hold, Fixed Rest, Infinite Loop. Also known as tidal breathing. Can be as long as you want it.

The program measures a "Relaxed Pause" (breath-hold time after exhale) and saves it to `relaxedPauseData.txt` for progress tracking

## Screenshots

![Delete option & Type A Training](https://raw.githubusercontent.com/Jakob-Tvalfager/ApneaTraining/main/images/DemoDeleteAndTypeA.webp)
![Persistent storage & Type B training](https://raw.githubusercontent.com/Jakob-Tvalfager/ApneaTraining/main/images/DemoPersistentStorageAndTypeB.webp)

## Usage

### Running Binaries
Precompiled binaries are provided in the `bin` folder:
- Linux: `apnea_linux`

Download the appropriate binary and run:
- Linux:
  ```bash
  chmod +x bin/apnea_linux
  ./bin/apnea_linux
  ```

### Compilation Instructions

#### Linux
1. Install GCC:
   ```bash
   sudo apt-get install gcc
   ```
2. Compile:
   ```bash
   .../ApneaTraining$ gcc -Wall -std=c11 apneaTraining.c -o ./bin/apnea_linux
   ```
3. Run:
   ```bash
   ./bin/apnea_linux
   ```

## Requirements

- **Linux**: GCC, Ubuntu linux has been tested. (Needed for `unistd.h`, `sleep`)

## Notes

- The program creates and reads from `relaxedPauseData.txt` in the working directory. [todo: use ini file instead]

## sources

Audio effects: https://pixabay.com/sound-effects/
Newer versions will use a recording.
