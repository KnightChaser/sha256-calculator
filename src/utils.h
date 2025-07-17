// src/utils.h

#ifndef UTILS_H
#define UTILS_H

#include <stddef.h> // For size_t

// Function to convert a byte array to a hex string
// output must be pre-allocated with at least (len * 2) + 1 bytes.
void bytes_to_hex_string(unsigned char *bytes, size_t len, char *output);

#endif // UTILS_H
