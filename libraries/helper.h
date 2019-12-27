#ifndef __SRC_HELPER_H
#define __SRC_HELPER_H

// #define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(arg)    (Serial.print(arg))
#define DEBUG_PRINTLN(arg)  (Serial.println(arg))
#else
#define DEBUG_PRINT(arg)
#define DEBUG_PRINTLN(arg)
#endif

#endif