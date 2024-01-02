#include "process.h"

namespace wmml
{
    Process::~Process()
    {
        this->CloseProcess();
    }

    bool Process::OpenProcess(DWORD process_id, DWORD desired_access)
    {
        if(this->process_handle_ != nullptr)
        {
            return false;
        }

        HANDLE process_handle = ::OpenProcess(desired_access, FALSE, process_id);
        if(!process_handle)
        {
            return false;
        }

        this->process_handle_ = process_handle;

        bool update_status = this->Update();
        return update_status;
    }

    bool Process::CloseProcess()
    {
        HANDLE process_handle = this->process_handle_;
        if(process_handle == nullptr)
        {
            return false;
        }

        CloseHandle(process_handle);
    
        this->process_handle_ = nullptr;
    
        return true;
    }

    bool Process::Update(MemoryAdapterPtr memory_adapter)
    {
        DWORD full_image_name_length = this->kFullImageNameLength;

        std::string full_image_name;
        full_image_name.resize(full_image_name_length);
        
        if(QueryFullProcessImageNameA(
            this->process_handle_, 
            0,
            full_image_name.data(), 
            &full_image_name_length) == FALSE)
        {
            return false;
        }

        full_image_name.resize(full_image_name_length);

        this->full_image_name_ = std::move(full_image_name);

        if(memory_adapter != nullptr)
        {
            this->memory_adapter_ = memory_adapter;
        }

        return true;
    }

} // namespace wmml
