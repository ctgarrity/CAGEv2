#ifndef RENDERER_H
#define RENDERER_H

#define VK_USE_PLATFORM_WIN32_KHR
#define VK_NO_PROTOTYPES
#include "external/volk.h"

#include <string>
#include <unordered_set>
#include <vector>
#include <cassert>
#include "SDL3/SDL.h"

#define VK_CHECK(func)                                  \
{                                                       \
    const VkResult result = func;                       \
    if (result != VK_SUCCESS) {                         \
        std::cerr << "Error calling function " << #func \
                    << " at " << __FILE__ << ":"        \
                    << __LINE__ << ". Result is "       \
                    << string_VkResult(result)          \
                    << std::endl;                       \
        assert(false);                                  \
    }                                                   \
}

class Renderer {
public:
    Renderer();
    ~Renderer();
    void Init();

private:
    void InitVolk();
    void InitSDL();
    void CreateInstance();

    SDL_Window* m_window = nullptr;
    std::vector<const char*> m_instanceExtensions = {};
};

#endif //RENDERER_H