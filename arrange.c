#include "arrange.h"

#include "arrange_default.h"



// ---------------------------------------------------------
// choose implementation here
// ---------------------------------------------------------
int arrange_on_new_window(  WMWorkspace* workspace, 
                            WMWindow* window){
    return default_on_new_window(workspace, window);
}

int arrange_on_del_window(  WMWorkspace* workspace, 
                            WMWindow* window){
    return default_on_del_window(workspace, window);
}

int arrange_on_key_press(int keysym){
    return default_on_key_press(keysym);
}
// ---------------------------------------------------------

