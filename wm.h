#ifndef WM_H
#define WM_H

#include <X11/Xlib.h> 
#include <X11/keysym.h> 

#include "common.h"
#include "workspace.h"
#include "window.h"


typedef struct{
    Display* display;
    Window root_window;
    int to_exit;

    WMWorkspace workspaces[NUM_OF_WORKSPACES];
    int current_workspace_index;
}Manager;

static Manager wm;

typedef struct{
    void* ptr;
}Args;

typedef struct{
    unsigned int mod;
    KeySym keysym;
    void (*func) (Args* args);
    Args args;
} Key;

// ------------------------------------------------------------------
// functions exported for key bindings
// ------------------------------------------------------------------
void spawn(Args* args);
void to_exit(Args* args);
// ------------------------------------------------------------------

// ------------------------------------------------------------------
// Key bindings configuration
// ------------------------------------------------------------------

// the mod key is winkey
#define MODKEY Mod4Mask

static const char* termcmd[] = {"st", NULL};

static Key wm_keys[] = {
    {MODKEY,    XK_Return,      spawn,      {.ptr = termcmd } },
    {MODKEY,    XK_E,           to_exit,       {.ptr = NULL } }
};

// ------------------------------------------------------------------

int main();

#endif

