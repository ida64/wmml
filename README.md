
# Windows Memory Manipulation Library (WMML)

abstract memory manipulation library for Windows.
## Demo

WMML uses Google's [GoogleTest](https://github.com/google/googletest) library for testing and example usage.

![Unit Testing with gtest](https://i.ibb.co/HYR8Q7y/image.png)

To run tests, build with `UnitTest_x64` or `UnitTest_x86` platforms and run the resulting unit test binary.

## Usage/Examples

```cpp
std::unique_ptr<Process> process = std::make_unique<Process>();

if(!process->OpenProcess(process_id, PROCESS_ALL_ACCESS))
{
...
}

std::shared_ptr<DefaultAdapter> memory_adapter
    = std::make_shared<DefaultAdapter>();

if(!process->Update(memory_adapter))
{
...
}
```

## Building

You can use the [premake5](https://premake.github.io/) generator to create the project files required to build WMML.

## Authors

- [@ida64 / paging](https://www.github.com/ida64)
