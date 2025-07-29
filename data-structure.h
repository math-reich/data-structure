/* data-structure.h */

#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>
// #include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>

// o tamanho dos ints mudam de acordo com a arquitetura do computador, então um computador de 64bits
// o int seria de 32bits, e o long de 64, para padronizar é usado long long int que sempre será 64bits
// no nosso caso não precisamos disso
// type of int bytes  --   RANGE ↓↓
typedef uint8_t   u8;   // 255
typedef int8_t    s8;   // (-128) to (+127)
typedef uint16_t  u16;  // 65 536
typedef int16_t   s16;  // (-32 768) to (+32 767)
typedef uint32_t  u32;  // 4 294 967 295
typedef int32_t   s32;  // (-2 147 583 648) to (+2 147 483 647)
typedef uint64_t  u64;  // 18 446 744 073 709 551 615
typedef int64_t   s64;  // (-9 223 372 036 854 775 808) to (+9 223 372 036 854 775 807)

// this types are used differently in scanf and printf depending of the type
// type  -  USAGE
// u8 -     hhu (half half unsined)
// s8 -     hhd (half half decimal)
// u16 -    hu (half unsigned)
// s16 -    hd (half decimal)
// u32 -    u (unsigned)
// s32 -    d (decimal)
// u64 -    llu (long long unsigned)
// s64 -    lld (long long decimal)

int main(int, char**);

// recreate my readLine function
#endif