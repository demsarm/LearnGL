#ifndef GLWINDOW_STRUCTS_HPP
#define GLWINDOW_STRUCTS_HPP

struct Color {
	uint8_t r, g, b, a;
};

struct ColorF {
	float r, g, b, a;
};

struct Point {
	int x, y;
};

struct Rect {
	int x, y, w, h;
};


inline ColorF ColorToColorF(const Color &color) {
	return {(float)color.r / 255.0f, (float)color.g / 255.0f, (float)color.b / 255.0f, (float)color.a / 255.0f};
}

#endif //GLWINDOW_STRUCTS_HPP
