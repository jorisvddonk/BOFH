#ifndef BME_CFG_H
#define BME_CFG_H

// BME configuration (some static things)

#define MAX_JOYSTICKS 16        // Maximum joysticks
#define MAX_HANDLES 16 	        // Up to 16 simultaneus files open from the
				// datafile

#define MAX_COLORS 256          // 8bit oldskool mode

#define DEFAULT_MAX_SPRFILES 256 // Default maximum of 256 spritefiles, though
                                 // this can be set during running of program

#ifndef __EMSCRIPTEN__
#define MAX_KEYS 512
#else
#define MAX_KEYS 2048
#endif

#endif
