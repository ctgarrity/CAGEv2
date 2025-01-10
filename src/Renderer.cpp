#include "Renderer.h"
#include "SDL3/SDL_vulkan.h"
#include "vulkan/vk_enum_string_helper.h"
#include <iostream>

Renderer::Renderer() {
    Init();
}

Renderer::~Renderer() {

}

void Renderer::Init() {
    InitVolk();
    InitSDL();
}

void Renderer::InitVolk() {
    VK_CHECK(volkInitialize());
    std::cout << "volk initialized" << std::endl;
}

void Renderer::InitSDL() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    auto windowFlags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY);
    m_window = SDL_CreateWindow("Connor's Amateur Game Engine", 1280, 720, windowFlags);
    if (!m_window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        throw std::runtime_error("Failed to create window!");
    }

    Uint32 extensionCount = 0;
    const char* const* instanceExtensions = SDL_Vulkan_GetInstanceExtensions(&extensionCount);
    for (int i = 0; i < extensionCount; i++) {
        m_instanceExtensions.push_back(instanceExtensions[i]);
    }

    std::cout << "SDL3 initialized" << std::endl;
}

void Renderer::CreateInstance() {
    const VkApplicationInfo appInfo = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = "CAGEv2 Renderer",
        .applicationVersion = VK_MAKE_API_VERSION(0, 1, 0, 0),
        .apiVersion = VK_MAKE_API_VERSION(0, 1, 3, 0)
    };

    /*const VkInstanceCreateInfo createInfo = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &appInfo,
        .enabledLayerCount =
    }*/

}
