#pragma once

namespace vec2 {

/// A 2-dimensional integer-based vector.
struct Vec2 {
  int x;
  int y;

  bool operator==(const Vec2 &rhs) { return x == rhs.x && y == rhs.y; }

  friend Vec2 operator+(Vec2 lhs, const Vec2 &rhs) {
    return Vec2{lhs.x + rhs.x, lhs.y + rhs.y};
  }

  friend Vec2 operator-(Vec2 lhs, const Vec2 &rhs) {
    return Vec2{lhs.x - rhs.x, lhs.y - rhs.y};
  }

  friend Vec2 operator*(const Vec2 &vec, int scalar) {
    return Vec2{vec.x * scalar, vec.y * scalar};
  }

  Vec2 &operator+=(const Vec2 &rhs) {
    *this = *this + rhs;
    return *this;
  }

  Vec2 &operator-=(const Vec2 &rhs) {
    *this = *this - rhs;
    return *this;
  }

  Vec2 &operator*=(int scalar) {
    *this = *this * scalar;
    return *this;
  }
};

/* Constants for useful vectors. */

static const Vec2 up = Vec2{0, -1};
static const Vec2 down = Vec2{0, 1};
static const Vec2 left = Vec2{-1, 0};
static const Vec2 right = Vec2{1, 0};
static const Vec2 zero = Vec2{0, 0};

}; // namespace vec2
