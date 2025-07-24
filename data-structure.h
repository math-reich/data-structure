/* data-structure.h */

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
typedef uint8_t   u8;   // 255
typedef int8_t    s8;   // (-128) to (+127)
typedef uint16_t  u16;  // 65 536
typedef int16_t   s16;  // (-32 768) to (+32 767)
typedef uint32_t  u32;  // 4 294 967 295
typedef int32_t   s32;  // (-2 147 583 648) to (+2 147 483 647)
typedef uint64_t  u64;  // 18 446 744 073 709 551 615
typedef int64_t   s64;  // (-9 223 372 036 854 775 808) to (+9 223 372 036 854 775 807)

int main(int, char**);

// create my own type of dynamic-array

// recreate my readLine function