#include "..\include\LogLevels\Commands.h"

#include "Settings.h"


// # PlaygroundLogLevels
bool Cmd_PlaygroundLogLevels_Execute(COMMAND_ARGS)
{
    logz(std::string(__func__) + "`Open")
    
    char	data[512];
    if(ExtractArgs(PASS_EXTRACT_ARGS, &data))
    {
        logz(std::string("data:") + data)
    }
    
    logz(std::string(__func__) + "`Close")
    return true;
}

DEFINE_COMMAND_PLUGIN(PlaygroundLogLevels, "Playground command", 0, 1, kParams_OneString)
