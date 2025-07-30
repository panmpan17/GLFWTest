#pragma once

#include <print>
#include <format>
#include <iostream>

#ifndef DEBUG_FLAG
#define DEBUG_FLAG 1
#endif

#define IS_DEBUG_VERSION (DEBUG_FLAG == 1)


#if IS_DEBUG_VERSION

#define LOG(msg) std::print(msg)
#define LOG_EX(msg, ...) std::print(msg, __VA_ARGS__)

#define LOGLN(msg) std::println(msg)
#define LOGLN_EX(msg, ...) std::println(msg, __VA_ARGS__)

#define LOGERR(msg) std::println("\033[91m{}\033[0m", msg)
#define LOGERR_EX(msg, ...) std::cout << "\033[91m" << std::format(msg, __VA_ARGS__) << "\033[0m";

#define LOGERRLN(msg) std::println("\033[91m{}\033[0m", msg)
#define LOGERRLN_EX(msg, ...) std::cout << "\033[91m" << std::format(msg, __VA_ARGS__) << "\033[0m" << std::endl;

#define ASSERT(condition, msg) \
    do { \
        if (!(condition)) { \
            std::println("Assertion failed: {}", msg); \
            exit(1); \
        } \
    } while (0)

// A macro to make it easy to use
// #define GL_CHECK() \
//     do { \
//         GLenum error;\
//         while ((error = glGetError()) != GL_NO_ERROR) {\
//             std::println("OpenGL Error: {} at {}:{}", error, __FILE__, __LINE__);\
//         }\
//     } while (0)

#else

#define LOG(msg) do {} while (0)
#define LOG_EX(msg, ...) do {} while (0)

#define LOGLN(msg) do {} while (0)
#define LOGLN_EX(msg, ...) do {} while (0)

#define ASSERT(condition, msg) do {} while (0)

#define LOGERR(msg) do {} while (0)
#define LOGERR_EX(msg, ...) do {} while (0)

#define LOGERRLN(msg) do {} while (0)
#define LOGERRLN_EX(msg, ...) do {} while (0)

#endif