# tests/meson.build

test_utils_exe = executable(
  'test_utils',
  'test_utils.c',
  files('../src/utils.c'),
  include_directories: '../src',
)

test('Utils functionality test', test_utils_exe)
