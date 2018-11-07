#include <QtWidgets/QWidget>
#include <QAction>
#include <engine/core/base/class_method_bind.h>
#include "QMessageHandler.h"

namespace Echo
{
	void qConnect(QWidget* sender, const char* signal, void* receiver, ClassMethodBind* slot)
	{
		if (sender)
		{
			QObject::connect(sender, signal, QMessageHandler::instance(), SLOT(onReceiveMessage()));
		}
	}

	QWidget* qFindChild(QWidget* root, const char* name)
	{
		QWidget* widget = root->findChild<QWidget*>(name);
		return widget;
	}

	void qDeleteWidget(QWidget*& widget)
	{
		if (widget)
		{
			delete widget;
			widget = nullptr;
		}
	}
}
