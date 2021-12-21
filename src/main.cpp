#include "main.hpp"
#include "AnyMiss.hpp"
#include "AnyMissConfig.hpp"

DEFINE_CONFIG(AnyMissConfig);

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    getAnyMissConfig().Init(modInfo);
    getLogger().info("Completed AnyMiss setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Installing AnyMiss...");
    AnyMiss::Install();
    getLogger().info("Installed AnyMiss!");
}