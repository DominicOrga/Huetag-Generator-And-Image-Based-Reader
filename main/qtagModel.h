#pragma once

#include "qstring.h"

namespace model
{
	// A detail namespace is one way of saying that its members are considered private.
	namespace detail
	{
		void serialize();

		//QMap<QString, qint8> markerMap;
		QString path = "C:\\Qt\\quinary_id.qtag";
	}

	/** Called once at the start of the application. Deserializes the markers. */
	void deserialize();

	void addMarker(QString data, qint8 id);
	void deleteMarker(QString data);
	bool containsMarker(QString data);

}