import QtQuick 2.5
import QtQuick.Controls 1.4
import QtControlLayer 1.0

Slider {
	id: slider
	property QObjProperty prop

	enabled: prop ? prop.enabled : true
	value: prop ? prop.normalizedValue : 0.0
	minimumValue: 0.0
	maximumValue: 1.0

	onValueChanged: {
		if (prop) {
			prop.normalizedValue = slider.value
		}
	}

	Connections {
		target: prop
		onNormalizedValueChanged: {
			value = prop.normalizedValue
		}
	}
}
