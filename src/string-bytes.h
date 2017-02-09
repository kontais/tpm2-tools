#ifndef STRING_BYTES_H
#define STRING_BYTES_H

#include <stdbool.h>
#include <stdint.h>

#include <sapi/tpm20.h>

int str2ByteStructure(const char *inStr, UINT16 *byteLenth, BYTE *byteBuffer);
int hex2ByteStructure(const char *inStr, UINT16 *byteLenth, BYTE *byteBuffer);

/**
 * Converts a numerical string into a uint32 value.
 * @param str
 *  The numerical string to convert.
 * @param value
 *  The value to store the conversion into.
 * @return
 *  true on success, false otherwise.
 */
bool string_bytes_get_uint32(const char *str, uint32_t *value);

/**
 * Converts a numerical string into a uint16 value.
 * @param str
 *  The numerical string to convert.
 * @param value
 *  The value to store the conversion into.
 * @return
 *  true on success, false otherwise.
 */
bool string_bytes_get_uint16(const char *str, uint16_t *value);

/**
 * Prints a TPM2B as a hex dump
 * @param buffer the TPM2B to print.
 */
void string_bytes_print_tpm2b(TPM2B *buffer);

/**
 * Copies a tpm2b from dest to src and clears dest if src is NULL.
 * If src is NULL, it is a NOP.
 * @param dest
 *  The destination TPM2B
 * @param src
 *  The source TPM2B
 * @return
 *  The number of bytes copied.
 */
UINT16 string_bytes_copy_tpm2b(TPM2B *dest, TPM2B *src);

/**
 * Checks if the host is big endian
 * @return
 *  True of the host is big endian false otherwise.
 */
bool string_bytes_is_host_big_endian(void);

/**
 * Swaps the endianess of 16 bit value.
 * @param data
 *  A 16 bit value to swap the endianess on.
 * @return
 * The 16 bit value with the endianess swapped.
 */
UINT16 string_bytes_endian_convert_16(UINT16 data);

/**
 * Just like string_bytes_endian_convert_16 but for 32 bit values.
 */
UINT32 string_bytes_endian_convert_32(UINT32 data);

/**
 * Just like string_bytes_endian_convert_16 but for 64 bit values.
 */
UINT64 string_bytes_endian_convert_64(UINT64 data);

/*
 * Leave the old interfaces for now and mark as deprecated,
 * on porting activities fix-up callers of these.
 */
#define deprecated __attribute__ ((deprecated))
static inline int deprecated getSizeUint16(const char *arg, UINT16 *num) {

    return !string_bytes_get_uint16(arg, num);
}

static inline int deprecated getSizeUint16Hex(const char *arg, UINT16 *num) {

    return !string_bytes_get_uint16(arg, num);
}

static inline int deprecated getSizeUint32(const char *arg, UINT32 *num) {

    return !string_bytes_get_uint32(arg, num);
}

static inline int deprecated getSizeUint32Hex(const char *arg, UINT32 *num) {

    return !string_bytes_get_uint32(arg, num);
}

static inline void deprecated PrintSizedBuffer(TPM2B *buffer) {
    string_bytes_print_tpm2b(buffer);
}

#undef deprecated

#endif /* STRING_BYTES_H */
