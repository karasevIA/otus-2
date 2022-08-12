#include <include/ip_base.h>
#include <string>

ip_base::ip_base(const std::string& s) noexcept {
    const std::size_t byte_count = 4;
    std::size_t ip_string_len = 0;
    std::size_t last_pos = 0;
    try { 
        for (auto i = 0; i < byte_count; ++i) {
            std::size_t digits_pos;
            std::size_t point_pos = s.find_first_of('.', last_pos);
            std::size_t byte = std::stoi(s.substr(last_pos), &digits_pos);
            
            if (byte > UINT8_MAX) return; //"355.-1.0.0"
            if (!std::isdigit(s[last_pos])) return; //"12.255.4. 2"
            if (i < byte_count - 1) {
                if (point_pos == std::string::npos) return; //"192.168.blabla"
                if (point_pos  - last_pos > digits_pos) return; //"12.1aaav2.0.0" 
            }
            ip_ += (ip_ << 8) + byte; //pack adress to uint32
            last_pos = point_pos + 1;
            ip_string_len += digits_pos + 1;
        }
        ip_string = s.substr(0, ip_string_len - 1);
        empty_ = false;
    } catch (...) {}
}

bool ip_base::operator<(const ip_base& b) noexcept {
    if (this->empty_) {
        return true;
    }
    return this->ip_ < b.ip_;
}

const std::string ip_base::string() const noexcept {
    return ip_string;
}

bool ip_base::empty() const noexcept{
    return empty_;
}