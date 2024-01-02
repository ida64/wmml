#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <memory>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

#include "memory_adapter.h"

/*
* Process represents a running process on the system.
* It is used to read/write memory and retrieve information about the process.
* 
    std::unique_ptr<Process> process = std::make_unique<Process>();
    std::shared_ptr<DefaultAdapter> memory_adapter
        = std::make_shared<DefaultAdapter>();

    if(!process->OpenProcess(process_id, PROCESS_ALL_ACCESS))
    {
    ...
    }

    if(!process->Update(memory_adapter))
    {
    ...
    }
*/

namespace wmml
{
    class Process
    {
    public: // Constructors and Destructor
        Process() = default;
        Process(const Process&) = delete;
        Process(Process&&) = delete;

        ~Process();

    public: // Public Member Functions
        /**
        * @brief open process handle and initialize fields
        * @param process_id process id
        * @param desired_access desired access to the process
        * @return true if successful, false otherwise
        */
        bool OpenProcess(DWORD process_id, DWORD desired_access);

        /**
        * @brief close process handle
        * @return true if successful, false otherwise
        */
        bool CloseProcess();

        /**
        * @brief update process information
        * @param [optional] memory_adapter memory adapter to use for reading/writing
        * @return true if successful, false otherwise
        */
        bool Update(MemoryAdapterPtr memory_adapter = nullptr);

        /**
        * @brief retrieve full_image_name_ member variable
        * @return full image name of the process
        */
        inline std::string GetFullImageName() const;

        /**
        * @brief retrieve process_handle_ member variable
        * @return process handle
        */
        inline HANDLE GetProcessHandle() const;

        /**
        * @brief retrieve memory_adapter_ member variable
        * @return memory adapter
        */
        inline MemoryAdapterPtr GetMemoryAdapter() const;

    private: // Private Member Variables
        HANDLE process_handle_ = nullptr;
        DWORD process_id_ = 0;

        /**
        * @brief the size to allocate for full_image_name_
        */
        static constexpr int kFullImageNameLength = 256;

        std::string full_image_name_;

        /**
        * @brief memory adapter to use for reading/writing
        * @note call Update to set this field (required for R/W)
        */
        MemoryAdapterPtr memory_adapter_ = nullptr;

    }; // class Process

} // namespace wmml

#include "process.inl"

#endif // PROCESS_H
