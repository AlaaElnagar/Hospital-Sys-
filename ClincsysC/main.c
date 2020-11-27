#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"

extern void ScreenInit(void);

int main(void)
{
    ScreenInit();
    while( ModeSelect());

}


