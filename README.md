# sha256-calculator
> A simple GUI-based SHA-256 calculator for any given string in real-time, made with GTK3 and OpenSSL's libcrypto.

### Preview
<img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/73f3a96e-24dd-45cd-a44c-7e4169e24bc9" />

### Build
Actually, I made this project to try out [Meson (The build system)](https://mesonbuild.com/Build-targets.html).
With Meson, developers can build and test their programs more easily.

1. Clone the Git repository
2. Hit `meson setup build` to create the source directory. (Later, if you made structural/fundamental changes to the code base, hit `meson setup build --reconfigure` to refresh)
<img width="800" height="400" alt="image" src="https://github.com/user-attachments/assets/6de7cffd-8c82-4fe6-a95f-584b5d280aec" />

3. **Inside the build directory**, hit `meson test` to run the test. Test codes are written in `tests/`
<img width="600" height="300" alt="image" src="https://github.com/user-attachments/assets/fdd7efe5-b70d-470b-8edf-10a713863776" />

4. **Inside the build directory**, hit `meson compile` to build the source and yield the executable. Source codes are written in `src/`
<img width="600" height="300" alt="image" src="https://github.com/user-attachments/assets/c798d0c4-1535-4705-a6d9-a6e35dbddbf8" />

