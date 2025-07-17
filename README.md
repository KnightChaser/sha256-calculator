# sha256-calculator
> A simple GUI-based SHA-256 calculator for any given string in real-time, made with GTK3 and OpenSSL's libcrypto.

### Preview
<img width="400" height="200" alt="image" src="https://github.com/user-attachments/assets/73f3a96e-24dd-45cd-a44c-7e4169e24bc9" />

### Build
Actually, I made this project to try out [Meson (The build system)](https://mesonbuild.com/Build-targets.html).
With Meson, developers can build and test their programs more easily.

1. Clone the Git repository
2. Hit `meson setup build` to create the source directory. (Later, if you made structural/fundamental changes to the code base, hit `meson setup build --reconfigure` to refresh)
<img width="600" height="300" alt="image" src="https://github.com/user-attachments/assets/acf64241-760e-4651-a45a-88f4909eb257" />

3. **Inside the build directory**, hit `meson test` to run the test. Test codes are written in `tests/`
<img width="600" height="300" alt="image" src="https://github.com/user-attachments/assets/8d5ac220-0ff5-430b-b2ce-ad9ce0ca550d" />

4. **Inside the build directory**, hit `meson compile` to build the source and yield the executable. Source codes are written in `src/`
<img width="600" height="300" alt="image" src="https://github.com/user-attachments/assets/7737f4bf-32d7-49d5-9a34-c38900371b95" />
