# tests/meson.build

test_utils_exe = executable(
  'test_utils',
  'test_utils.c',
  link_with: utils_lib, # Link with the utils library
  include_directories: include_directories('../src'), # test_utils.c directly imports "../src/utils.h" anyway
)

test('Utils functionality test', test_utils_exe)
