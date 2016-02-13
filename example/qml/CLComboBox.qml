import QtQuick 2.5
import QtQuick.Controls 1.4
import QtControlLayer 1.0

ComboBox {
	id: comboBox
	property QObjProperty prop: null
	currentIndex: prop ? prop.value : 0
	model: prop ? prop.strings : null
	Connections {
		target: prop
		onValueChanged: {		
			currentIndex = prop.value;
		}
	}

	onCurrentIndexChanged: {
		if (prop) {
			prop.value = currentIndex;
		}
	}

	onPropChanged: {
		if (prop) {
			currentIndex = prop.value;
		}
	}
}