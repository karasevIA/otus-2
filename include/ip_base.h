#pragma once

#pragma once

#include <string>

class ip_base {
public:
    ip_base(const std::string& s) noexcept;
    ~ip_base() = default;
    const std::string string() const noexcept;
    bool empty() const noexcept;
    bool operator<(const ip_base& b) const noexcept;
    uint8_t get_byte(std::size_t n) const noexcept;
private:
    std::string ip_string;
    bool empty_ = true;
protected:
    uint32_t ip_= 0;
public:
    static constexpr std::size_t byte_count = 4;  
};
