# Adventure-Game
# Installation and Running Instructions

## Option 1: Download and Run Ready Version (Recommended)

The easiest way to play the game is to download the compiled executable file.

### Steps:

1. Open the **Releases** section of this GitHub repository.

2. Download the latest version:

```
AdventureGame.zip
```

3. Extract the ZIP archive.

4. Open the extracted folder.

5. Run:

```
AdventureGame.exe
```

6. The game will start in the console window.

No additional software or programming tools are required.

---

# Option 2: Download Source Code and Build Manually

This option is for developers who want to view or modify the source code.

## Requirements

Before running the project, install:

* C++ compiler:

  * GCC / MinGW
  * Microsoft Visual C++ Compiler
  * Clang

* Git

* Code editor (recommended):

  * Visual Studio Code
  * Visual Studio
  * CLion

---

## Clone Repository

Open terminal or Git Bash and run:

```bash
git clone https://github.com/Perry1231/Adventure-Game.git
```

Go into the project folder:

```bash
cd Adventure-Game
```

---

# Building the Project

## Using G++

If you have GCC installed:

```bash
g++ *.cpp -o AdventureGame
```

After successful compilation, run:

### Windows:

```bash
AdventureGame.exe
```

### Linux/macOS:

```bash
./AdventureGame
```

---

## Using Visual Studio

1. Open Visual Studio.

2. Select:

```
Open a Local Folder
```

3. Choose the downloaded Adventure-Game folder.

4. Select:

```
Build → Build Solution
```

5. After successful compilation run the project:

```
Local Windows Debugger
```

---

# Using Visual Studio Code

1. Install extensions:

* C/C++ Extension by Microsoft
* CMake Tools (optional)

2. Open the project folder.

3. Open the terminal.

4. Compile:

```bash
g++ *.cpp -o AdventureGame.exe
```

5. Start the game:

```bash
./AdventureGame.exe
```

---

# Downloading via GitHub

You can download the project without Git:

1. Open the repository page.

2. Click:

```
Code → Download ZIP
```

3. Extract the archive.

4. Open the project folder.

5. Build or run the executable.

---

# Troubleshooting

## "g++ is not recognized" or "command not found"

This means that GCC is not installed.

Install one of the following:

* MinGW
* MSYS2
* Visual Studio C++ Build Tools

After installation restart your terminal.

Check installation:

```bash
g++ --version
```

---

## Windows blocks the .exe file

If Windows Defender shows a warning:

1. Click:

```
More info
```

2. Select:

```
Run anyway
```

The game is a locally compiled application.

---

# Running on Another Computer

To run the game on another PC:

1. Download:

```
AdventureGame.exe
```

2. Copy the file to another computer.

3. Double-click:

```
AdventureGame.exe
```

The computer does not need the source code or development tools.

---

# Automatic Builds

This project uses GitHub Actions to automatically compile the game.

Every update can generate a new executable version that can be downloaded from:

```
Repository → Actions → Latest Build → Artifacts
```

This allows users to download and play the newest version without compiling the source code manually.
