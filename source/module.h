#ifndef MODULE_H
#define MODULE_H

#include <string>

namespace wmml
{
    /**
    * @brief Module
     * 
     * @param image_name 
     * @param image_base 
     * @param image_size 
     */
    struct Module final
    {
        Module() = default;
        inline Module(const std::wstring& image_name, void* image_base, size_t image_size);

        ~Module() = default;

        std::wstring image_name_;
        void* image_base_ = nullptr;
        size_t image_size_ = 0;

    }; // struct Module

} // namespace wmml

#include "module.inl"

#endif // MODULE_H