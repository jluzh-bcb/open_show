#include <cstdlib>
#include <iostream>
#include <ctime>

int main() {
    std::srand(std::time(0));
    std::cout<<std::rand()%21+1;
}
