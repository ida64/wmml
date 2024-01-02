#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <memory>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

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
        * @return true if successful, false otherwise
        */
        bool Update();

        /**
        * @brief retrieve full_image_name_ member variable
        * @return full image name of the process
        */
        inline std::string GetFullImageName() const;

    private: // Private Member Variables
        HANDLE process_handle_ = nullptr;
        DWORD process_id_ = 0;

        /**
        * @brief the size to allocate for full_image_name_
        */
        static constexpr int kFullImageNameLength = 256;

        std::string full_image_name_;

    }; // class Process

} // namespace wmml

#include "process.inl"

#endif // PROCESS_H
