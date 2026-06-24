# Build Instructions

The project can be built from source using any modern C++ compiler. A precompiled executable is also available through GitHub Releases and GitHub Actions artifacts for users who do not wish to compile the source code manually.

## Requirements

Before building the project, make sure you have:

* A C++ compiler with C++17 support:

  * GCC / MinGW-w64
  * Microsoft Visual C++ (MSVC)
  * Clang
* Git (optional, for cloning the repository)
* Windows, Linux, or macOS operating system

---

## Clone the Repository

```bash
git clone https://github.com/Perry1231/Adventure-Game.git
cd Adventure-Game
```

---

## Building with GCC (Recommended)

Compile all source files into a single executable:

```bash
g++ -static-libgcc -static-libstdc++ -static *.cpp -o AdventureGame.exe
```

### Why use static linking?

The static build includes all required runtime libraries directly inside the executable. This allows the game to run on other Windows computers without requiring MinGW, MSYS2, or additional DLL files.

After compilation, run:

```bash
AdventureGame.exe
```

---

## Building with Visual Studio Code

1. Install the **C/C++ Extension** by Microsoft.
2. Open the project folder.
3. Open the integrated terminal.
4. Build the project using:

```bash
g++ -static-libgcc -static-libstdc++ -static *.cpp -o AdventureGame.exe
```

5. Run the generated executable:

```bash
./AdventureGame.exe
```

---

## Building with Microsoft Visual Studio

1. Open Visual Studio.
2. Select **Open a Local Folder**.
3. Choose the Adventure-Game project folder.
4. Build the solution using:

```text
Build → Build Solution
```

5. Start the game:

```text
Local Windows Debugger
```

---

## GitHub Actions Automatic Builds

This repository includes GitHub Actions workflows that automatically compile the project whenever changes are pushed to the repository.

To download the latest automatically generated build:

1. Open the repository on GitHub.
2. Navigate to:

```text
Actions → Latest Successful Workflow
```

3. Download the generated artifact:

```text
AdventureGame.zip
```

4. Extract the archive.
5. Run:

```text
AdventureGame.exe
```

No compiler or development tools are required when using a prebuilt release.

---

## Running on Another Computer

The executable generated using static linking can be copied directly to another Windows computer.

Steps:

1. Build the project.
2. Copy:

```text
AdventureGame.exe
```

3. Transfer the file to another PC.
4. Double-click the executable to start the game.

No source code, compiler, or external libraries are required.

---

## Troubleshooting

### g++: command not found

The GCC compiler is not installed or not added to the system PATH.

Install one of the following:

* MinGW-w64
* MSYS2
* Visual Studio Build Tools

Verify installation:

```bash
g++ --version
```

---

### Windows Defender Warning

Because the executable is not digitally signed, Windows SmartScreen may display a warning.

To continue:

```text
More Info → Run Anyway
```

This behavior is common for independent and educational projects.

---

### Compilation Errors

If compilation fails:

1. Verify that all `.cpp` files are present.
2. Confirm that your compiler supports C++17.
3. Ensure all project files are located in the same directory.
4. Check that no source files have been renamed or removed.

---

## Build Output

Successful compilation creates:

```text
AdventureGame.exe
```

This executable contains the complete game and can be distributed to other Windows users without additional dependencies.
