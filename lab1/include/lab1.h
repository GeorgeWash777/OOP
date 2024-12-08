#pragma once

bool is_valid_int_input(bool is_value_valid);
std::string intToBinary(long long n) {
    std::string binary = "";
    for(int i = 0; i < 32; i++) {
    if(n & (1 << i))
        binary = "1" + binary;
    else
        binary = "0" + binary;
    }
    return binary;
}