// tests/test_utils.c
#include "../src/utils.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
  // Test case 1: Basic conversion
  unsigned char bytes1[] = {0xDE, 0xAD, 0xBE, 0xEF};
  char hex_output1[9]; // 4 bytes * 2 chars/byte + 1 null terminator
  bytes_to_hex_string(bytes1, sizeof(bytes1), hex_output1);
  printf("Test 1: Expected DEADBEEF, Got %s\n", hex_output1);
  assert(strcmp(hex_output1, "deadbeef") == 0);

  // Test case 2: Single byte
  unsigned char bytes2[] = {0x0F};
  char hex_output2[3]; // 1 byte * 2 chars/byte + 1 null terminator
  bytes_to_hex_string(bytes2, sizeof(bytes2), hex_output2);
  printf("Test 2: Expected 0f, Got %s\n", hex_output2);
  assert(strcmp(hex_output2, "0f") == 0);

  // Test case 3: Empty array (should result in empty string)
  unsigned char bytes3[] = {};
  char hex_output3[1]; // 1 null terminator
  bytes_to_hex_string(bytes3, 0, hex_output3);
  printf("Test 3: Expected (empty string), Got '%s'\n", hex_output3);
  assert(strcmp(hex_output3, "") == 0);

  printf("All tests passed!\n");
  return 0;
}
