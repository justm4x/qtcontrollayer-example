import QtQuick 2.5
import QtQuick.Controls 1.4

import QtControlLayer 1.0

ApplicationWindow {
	id: root
	property QObjProperty pCurrentIndex: ControlLayer.getProperty("/Example/CurrentIndex")

	width: 400
	height: 300
	visible: true

	CLButton {
		id: button	
		prop: ControlLayer.getProperty("/Example/Trigger");
		width: 80
		height: 24
		anchors.centerIn: parent
	}
}