#include <math.h>
#include "color.h"

namespace orga {

	XYZ RGBToXYZ(RGB rgb) {
		float r = rgb.R / 255.f;
		float g = rgb.G / 255.f;
		float b = rgb.B / 255.f;

		r = (r > 0.04045f) ? powf((r + 0.055f) / 1.055f, 2.4f) : r / 12.92f;
		g = (g > 0.04045f) ? powf((g + 0.055f) / 1.055f, 2.4f) : g / 12.92f;
		b = (b > 0.04045f) ? powf((b + 0.055f) / 1.055f, 2.4f) : b / 12.92f;

		float x = 0.436052025f * r + 0.385081593f * g + 0.143087414f * b;
		float y = 0.222491598f * r + 0.71688606f  * g + 0.060621486f * b;
		float z = 0.013929122f * r + 0.097097002f * g + 0.71418547f  * b;

		return XYZ{ x, y, z };
	}

	Lab XYZToLab(XYZ xyz) {
		float x = xyz.X;
		float y = xyz.Y;
		float z = xyz.Z;

		float X_r = 0.964221f;
		float Y_r = 1.0f;
		float Z_r = 0.825211f;

		float eps = 216.f / 24389.f;
		float k = 24389.f / 27.f;

		// XYZ to Lab
		float x_r = x / X_r;
		float y_r = y / Y_r;
		float z_r = z / Z_r;

		float f_x = (x_r > eps) ? powf(x_r, 1 / 3.f) : (k * x_r + 16) / 116.f;
		float f_y = (y_r > eps) ? powf(y_r, 1 / 3.f) : (k * y_r + 16) / 116.f;
		float f_z = (z_r > eps) ? powf(z_r, 1 / 3.f) : (k * z_r + 16) / 116.f;

		float L = (116 * f_y) - 16;
		float a = 500 * (f_x - f_y);
		float b = 200 * (f_y - f_z);

		return Lab{ L, a, b };
	}

	Lab RGBToLab(RGB rgb) {
		XYZ xyz = RGBToXYZ(rgb);
		return XYZToLab(xyz);
	}	
}