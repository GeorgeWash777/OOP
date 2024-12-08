#include "../include/lab1.h"


bool is_valid_int_input(bool is_value_valid) {
    char next_char = getchar();
    bool is_next_char_valid = (next_char == '\n' || next_char == EOF);

    if (!is_next_char_valid) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    if (std::cin.fail() || !is_value_valid || !is_next_char_valid) {
        std::cerr << "ERROR: Invalid input. Try again\n\n";
        return false;
    }
    return true;
}


// std::string intToBinary(int n) {
//     std::string binary = "";
//     for(int i = 0; i < 32; i++) {
//     if(n & (1 << i))
//         binary = "1" + binary;
//     else
//         binary = "0" + binary;
//     }
//     return binary;
// }