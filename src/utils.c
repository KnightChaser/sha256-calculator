// src/utils.c

#include "utils.h"
#include <stdio.h> // For sprintf

// Function to convert a byte array to a hex string
void bytes_to_hex_string(unsigned char *bytes, // [in]
                         size_t len,           // [in]
                         char *output          // [out]
) {
  for (size_t i = 0; i < len; i++) {
    snprintf(output + (i * 2), 3, "%02x", bytes[i]);
  }
  output[len * 2] = '\0'; // Null-terminate the string
}
