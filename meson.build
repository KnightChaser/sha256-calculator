# meson.build

project(
  'sha256_calculator',
  'c',
  version: '0.1.0',
  default_options: [
    'c_std=c11',
    'warning_level=2',
  ],
)

# Find GTk 3 (dependency)
gtk_dep = dependency('gtk+-3.0', version: '>= 3.0')

# Find OpenSSL's libcrypto (dependency)
crypto_dep = dependency('libcrypto', version: '>= 1.1')

# utils library
utils_lib = static_library(
  'utils', # Base name of the library
  'src/utils.c',
  include_directories: include_directories('src'), # When including this library, the src directory is needed
  install: false, # Not installed separately (e.g., /usr/local/lib)
)

# Source files
sources = files(
  'src/main.c',
  'src/sha256_gui.c',
)

# Create an executable
executable(
  'sha256_calculator_app',
  sources,
  dependencies: [gtk_dep, crypto_dep],
  link_with: [utils_lib],
  install: true,
)

subdir('tests')

message('SHA256 Calculator project configured successfully.')
