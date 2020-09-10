#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    FILE *fp1 = fopen(argv[1], "rb");
    FILE *fp2 = fopen(argv[2], "rb");

    uint8_t buf1[4] = {};
    uint8_t buf2[4] = {};
    uint32_t *p1 = reinterpret_cast<uint32_t*>(buf1);
    uint32_t *p2 = reinterpret_cast<uint32_t*>(buf2);

    fread(buf1, 4, 1, fp1);
    fread(buf2, 4, 1, fp2);

    uint32_t op1 = ntohl(*p1);
    uint32_t op2 = ntohl(*p2);
    uint32_t result = op1 + op2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", op1, op1, op2, op2, result, result);
    return 0;
}
