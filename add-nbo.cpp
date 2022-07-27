#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>
#define MAX sizeof(uint32_t)

uint32_t write32bitnbo(char filename[])
{
    FILE* fp = fopen(filename, "r");
    uint8_t buffer[MAX] = { 0x00, };
    fread(buffer, sizeof(uint8_t), MAX, fp);
    uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
    uint32_t n = ntohl(*p);
    fclose(fp);
    return n;
}

int main(int argc, char *argv[])
{
    uint32_t n1 = write32bitnbo(argv[1]);
    uint32_t n2 = write32bitnbo(argv[2]);
    uint32_t n3 = n1 + n2;

    printf("%d(%x) + %d(%x) = %d(%x)", n1, n1, n2, n2, n3, n3);

    return 0;
}
