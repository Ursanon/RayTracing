#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include <memory>
#include <vector>

#include "Material.hpp"
#include "Geometry.hpp"
#include "RenderSettings.hpp"

namespace bs
{
	class RayTracer
	{
	public:
		static std::vector<Vector3f> render(const RenderSettings& render_settings, const std::vector<std::unique_ptr<Geometry>>& world);
	
	private:
		//color
		static Vector3f cast_ray(const Ray& ray, int depth, const std::vector<std::unique_ptr<Geometry>>& world);
	};
}

#endif // !RAYTRACER_HPP_