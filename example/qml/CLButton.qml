import QtQuick 2.5
import QtQuick.Controls 1.4

import QtControlLayer 1.0

Button {
	id: button
	property QObjProperty prop : null

	text: prop ? prop.displayName : ""
	enabled: prop ? prop.enabled : true 

	Binding {
		target: prop
		property: "state"
		value: pressed
	}
}
