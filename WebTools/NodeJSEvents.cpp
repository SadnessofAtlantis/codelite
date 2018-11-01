#include "NodeJSEvents.h"

wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_STARTED, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_STOPPED, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_UPDATE_CALLSTACK, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_LOCALS_LOOKUP, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_TOOLTIP_LOOKUP, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_CAN_INTERACT, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_LOST_INTERACT, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_MARK_LINE, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_CONSOLE_LOG, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_SELECT_FRAME, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_EXCEPTION_THROWN, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_UPDATE_BREAKPOINTS_VIEW, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_EVAL_EXPRESSION, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_DEBUGGER_EXPRESSION_EVALUATED, clDebugEvent);

wxDEFINE_EVENT(wxEVT_NODEJS_CLI_DEBUGGER_STARTED, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_CLI_DEBUGGER_STOPPED, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_CLI_DEBUGGER_UPDATE_CALLSTACK, clDebugEvent);
wxDEFINE_EVENT(wxEVT_NODEJS_CLI_DEBUGGER_UPDATE_BREAKPOINTS_VIEW, clDebugEvent);
