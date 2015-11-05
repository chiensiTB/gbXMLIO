// gbxmlReadWriteCPP2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gbXMLIO.h"



// ---------------------------------------------------------------------------
//  This is a simple class that lets us do easy (though not terribly efficient)
//  trancoding of char* data to XMLCh data.
// ---------------------------------------------------------------------------




int _tmain(int argc, _TCHAR* argv[])
{
	string filePath = "test.xml";
	int errorCode = 0;
	int ABSOLUTE_PATH_FILENAME_PREFIX_SIZE = 9;
	{
		try
		{

			//make building
			BuildingStorey bs = BuildingStorey();
			bs.setId("Level 1");
			Name bName = Name();
			bs.setName(bName);
			Level bLevel = Level();
			bLevel.setValue("12.000");
			bs.setLevel(bLevel);
			bs.setName(bName);

			Area uArea = Area();
			uArea.setValue("2000");
			Building b = Building();
			b.setId("buildingGuid-F23423985Fgodgu");
			b.setBuildingType("office");
			b.setArea(uArea);
			b.setStorey(bs);

			//make location
			ZipCodeOrPostalCode aZ = ZipCodeOrPostalCode();
			aZ.setValue("10031");
			Longitude lo = Longitude();
			lo.setValue("-122.45");
			Latitude lat = Latitude();
			lat.Set("50");

			Name nm = Name();
			std::string namePlace = "Cincinatti, OH Downtown";
			nm.Set(namePlace);
			Location l = Location();
			l.SetName(nm);
			l.SetLatitude(lat);
			l.setLongitude(lo);
			l.setZipCode(aZ); //required field


			//create a campus element, and add it
			Campus c = Campus();
			c.setId("someID");
			c.SetLocation(l); //add location (required)
			c.setBuilding(b); //add a building (not required)
			
			//to create just a basic gbxml document
			gbXML gb = gbXML();
			gb.setLengthUnit("feet");
			gb.setAreaUnit("squarefeet");
			gb.setTemperatureUnits("F");
			gb.setVolumeUnits("cubicfeet");
			gb.setVersion("5.13");
			gb.setUseSIUnits(false);
			gb.setCampus(c);

			filePath = "rapidtest.xml";
			errorCode = gb.makegbxmlRapid(gb, filePath);
		}
		catch (const std::exception& e)
		{
			//Interrogate e.XXX member functions with information about the exeption thrown
			errorCode = 5;
		}


		
	}
	// Other terminations and cleanup.
	return errorCode;
}

