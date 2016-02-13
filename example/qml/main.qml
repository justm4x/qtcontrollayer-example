import QtQuick 2.5
import QtQuick.Controls 1.4

import QtControlLayer 1.0

ApplicationWindow {
	id: root
	property QObjProperty pCurrentIndex: ControlLayer.getProperty("/Example/CurrentIndex")

	width: 400
	height: 300
	visible: true

	Column {
		anchors.fill: parent
		anchors.margins: 4
		spacing: 4
		CLButton {
			prop: ControlLayer.getProperty("/Example/BooleanValue");
			anchors.left: parent.left
			anchors.right: parent.right
			implicitHeight: 30
		}
		CLSlider {
			prop: ControlLayer.getProperty("/Example/FloatValue");
			anchors.left: parent.left
			anchors.right: parent.right
			implicitHeight: 30
		}
		CLComboBox {
			prop: ControlLayer.getProperty("/Example/IntegerValue");
			anchors.left: parent.left
			anchors.right: parent.right
			implicitHeight: 30
		}
	}
}