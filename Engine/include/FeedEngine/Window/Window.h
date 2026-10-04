#pragma once

#include "../Core/Export.h"

namespace fe {
	class FE_API Window {
	public:
		virtual ~Window() = default;

    	virtual void Create(int width, int height, const char* title) = 0;

    	virtual void Update() = 0;

    	virtual bool ShouldClose() const = 0;
	};
}