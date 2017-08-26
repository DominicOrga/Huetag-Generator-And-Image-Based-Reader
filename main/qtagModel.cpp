#include "qtagModel.h"

#include "qfile.h"
#include "qdatastream.h"

namespace model
{
	namespace detail
	{
		void serialize()
		{
			/*QFile file(detail::path);

			if (file.open(QIODevice::WriteOnly))
			{
				QDataStream out(&file);
				out.setVersion(QDataStream::Qt_DefaultCompiledVersion);

				out << detail::markerMap;
			}

			file.close();*/
		}
	}

	void deserialize()
	{
		//QFile file(detail::path);

		//if (file.open(QIODevice::ReadOnly))
		//{
		//	QDataStream in(&file);
		//	in.setVersion(QDataStream::Qt_DefaultCompiledVersion);

		//	in >> detail::markerMap;	// Deserialize data of the markers.
		//}

		//file.close();
	}

	void addMarker(QString data, qint8 id)
	{
		/*if (containsMarker(data))
			return;
		
		detail::markerMap.insert(data, id);*/
	}

	void deleteMarker(QString data)
	{
		/*if (!containsMarker(data))
			return;

		detail::markerMap.remove(data);*/
	}

	bool containsMarker(QString data)
	{
		//return detail::markerMap.contains(data);
		return true;
	}

	QMap<QString, qint8> const* getMarkers()
	{
		//return &detail::markerMap;
		return nullptr;
	}
}
