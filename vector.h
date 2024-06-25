/*
struct for vector, used for aimbot calculations
*/
#pragma once
#include <numbers>
#include <cmath>

#include <cstdint>
constexpr float pi = 3.14159265358979323846f;

struct Vector3
{
	// constructor
	Vector3(
		const float x = 0.f,
		const float y = 0.f,
		const float z = 0.f) noexcept :
		x(x), y(y), z(z) { }

	// operator overloads
	const Vector3 operator-(const Vector3& other) const noexcept
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	const Vector3 operator+(const Vector3& other) const noexcept
	{
		return Vector3{ x + other.x, y + other.y, z + other.z };
	}

	const Vector3 operator/(const float factor) const noexcept
	{
		return Vector3{ x / factor, y / factor, z / factor };
	}

	const Vector3 operator*(const float factor) const noexcept
	{
		return Vector3{ x * factor, y * factor, z * factor };
	}

	// utils
	const Vector3 ToAngle() const noexcept
	{
		Vector3 result;
		result.x = std::atan2(-z, std::hypot(x, y)) * ((180.0f / pi));
		result.y = std::atan2(y, x) * (180.0f / pi);
		result.z = 0.f;
		return result;
	}

	const bool IsZero() const noexcept
	{
		return x == 0.f && y == 0.f && z == 0.f;
	}

	// struct data
	float x, y, z;
};
