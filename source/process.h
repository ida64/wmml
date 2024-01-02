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
        bool OpenProcess(DWORD process_id, DWORD desired_access);
        bool CloseProcess();

        bool Update();

        inline std::string GetFullImageName() const;

    private: // Private Member Variables
        HANDLE process_handle_ = nullptr;
        DWORD process_id_ = 0;

        std::string full_image_name_;
        static constexpr int kFullImageNameLength = 256;

    }; // class Process

} // namespace wmml

#include "process.inl"

#endif // PROCESS_H
