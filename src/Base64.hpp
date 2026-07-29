#pragma once

#include <stdexcept>
#include <string>

namespace Base64 {

static const std::string chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

inline std::string Decode(const std::string& input) {
    std::string output;

    int val = 0;
    int bits = -8;

    for(unsigned char c : input) {
        if(c == '=')
            break;

        auto pos = chars.find(c);
        if(pos == std::string::npos) {
            continue;
        }

        val = (val << 6) + static_cast<int>(pos);
        bits += 6;

        if(bits >= 0) {
            output.push_back(char((val >> bits) & 0xFF));
            bits -= 8;
        }
    }

    return output;
}

inline std::string Encode(const std::string& input) {
    std::string output;

    int val = 0;
    int bits = -6;

    for(unsigned char c : input) {
        val = (val << 8) + c;
        bits += 8;

        while(bits >= 0) {
            output.push_back(chars[(val >> bits) & 0x3F]);
            bits -= 6;
        }
    }

    if(bits > -6) {
        output.push_back(chars[((val << 8) >> (bits + 8)) & 0x3F]);
    }

    while(output.size() % 4)
        output.push_back('=');

    return output;
}

}