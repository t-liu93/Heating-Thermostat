#ifndef __HELPER_H
#define __HELPER_H

#ifdef DEBUG_BUILD
#define DEBUG_PRINT(arg)    (Serial.print(arg))
#define DEBUG_PRINTLN(arg)  (Serial.println(arg))
#else
#define DEBUG_PRINT(arg)
#define DEBUG_PRINTLN(arg)
#endif

#endif