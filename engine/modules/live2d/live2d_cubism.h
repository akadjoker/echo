#pragma once

#include "engine/core/scene/Node.h"

namespace Echo
{
	class Live2dCubism : public Node
	{
		ECHO_CLASS(Live2dCubism, Node)

	public:
		Live2dCubism();
		virtual ~Live2dCubism();

	protected:
		virtual void update();

	private:
		void*		m_model;
	};
}