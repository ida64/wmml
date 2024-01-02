#include "module.h"

namespace wmml
{
    inline Module::Module(const std::wstring& image_name, void* image_base, size_t image_size)
    {
        image_name_ = image_name;
        image_base_ = image_base;
        image_size_ = image_size;
    }

} // namespace wmml