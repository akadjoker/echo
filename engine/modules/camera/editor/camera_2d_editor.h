#pragma once

#include "../camera_2d.h"
#include "engine/core/base/object_editor.h"
#include "engine/core/gizmos/Gizmos.h"

namespace Echo
{
#ifdef ECHO_EDITOR_MODE
	class Camera2DEditor : public ObjectEditor
	{
	public:
		Camera2DEditor(Object* object);
		virtual ~Camera2DEditor();

		// get camera2d icon, used for editor
		const char* getEditorIcon() const;

		// on editor select this node
		virtual void onEditorSelectThisNode() override;

		// on editor update this
		virtual void editor_update_self() override;

	private:
		Gizmos*		m_gizmo;
		bool		m_isSelect;
	};
#endif
}