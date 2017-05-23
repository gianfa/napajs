#include "v8-common.h"

#include <napa-log.h>

#include <boost/dll/runtime_symbol_info.hpp>

// V8 libraries
#include <libplatform/libplatform.h>
#include <v8.h>

static v8::Platform* _platform = nullptr;

bool napa::v8_common::Initialize() {
    NAPA_ASSERT(!_platform, "V8 was already initialized");

    _platform = v8::platform::CreateDefaultPlatform();
    v8::V8::InitializePlatform(_platform);
    v8::V8::Initialize();

    return true;
}

void napa::v8_common::Shutdown() {
    NAPA_ASSERT(_platform, "V8 wasn't initialized");

    v8::V8::Dispose();
    v8::V8::ShutdownPlatform();

    delete _platform;
    _platform = nullptr;
}
