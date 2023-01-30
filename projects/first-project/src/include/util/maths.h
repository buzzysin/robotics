#ifndef _MATHS_H_
#define _MATHS_H_


// x if v < x, y if v > y, v otherwise
#define clamp(v, x, y) (min(max((x), (v)), y))

#define sgn(v) ((v) < 0 ? -1.0 : 1.0)

#endif