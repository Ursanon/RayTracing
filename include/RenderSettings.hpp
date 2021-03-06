#ifndef RENDERSETTINGS_HPP_
#define RENDERSETTINGS_HPP_

#include "Camera.hpp"

namespace rt
{
	struct RenderSettings
	{
		RenderSettings(const Camera& camera, const size_t& width, const size_t& height, const size_t& max_depth, const size_t& smooth_sampling, const float& clip_minimum)
			: target_camera(camera),
			width(width),
			height(height),
			max_depth(max_depth),
			smooth_sampling(smooth_sampling),
			clip_minimum(clip_minimum)
		{
		}

		const Camera& target_camera;

		const size_t width;
		const size_t height;
		const size_t max_depth;
		const size_t smooth_sampling;
		const float clip_minimum;
	};
}
#endif // !RENDERSETTINGS_HPP_