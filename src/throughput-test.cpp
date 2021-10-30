#include <unistd.h>

int main() {
    char buffer[8192] {'\0'};
    while (write(1, buffer, sizeof(buffer)) >= 0)
        ;
}
