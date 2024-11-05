#ifndef COLORS_H
#define COLORS_H

#include "raylib.h"
#include <vector>

namespace Colors {
	 inline const Color DarkGray { 26,31,40,255 };
	 inline const Color Green{ 47, 230, 23, 255 };
	 inline const Color Red{ 232, 18, 18, 255 };
	 inline const Color Orange{ 226, 116, 17, 255 };
	 inline const Color Yellow{ 237, 234, 4, 255 };
	 inline const Color Purple{ 166, 0, 247, 255 };
	 inline const Color Cyan{ 21, 204, 209, 255 };
	 inline const Color Blue{ 13, 64, 216, 255 };
	 inline const Color LightBlue{ 59, 85,162,255 };
	 inline const Color DarkBlue{ 44, 44, 127,255 };
	 inline const Color Black{ 0,0,0,255 };
	 inline const Color white{ 255,255,255,255 };

	 inline std::vector<Color> Colors = { DarkGray,Green,Red,Orange,Yellow,Purple,Cyan,LightBlue };
}
#endif // !COLORS_H


