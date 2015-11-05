
#include "stdafx.h"
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include <fstream>
#include <sstream>
// Other include files, declarations, and non-Xerces-C++ initializations.
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
using namespace rapidxml;

template <typename T>
class EnumParser
{
	map <string, T> enumMap; //see the enum in question for the map
public:
	EnumParser(){};

	T ParseSomeEnum(const string &value)
	{
		map <string, T>::const_iterator iValue = enumMap.find(value);
		if (iValue == enumMap.end())
			throw runtime_error("");
		return iValue->second;
	}

	string GetString(const T &value)
	{
		string key = "";
		for (auto &i : enumMap)
		{
			if (i.second == value) {
				key = i.first;
				break;
			}
		}
		if (key == "")
			throw runtime_error("");
		return key;
	}
};

enum areaUnitEnum {
	SQUAREKILOMETERS,
	SQUAREMETERS,
	SQUARECENTIMETERS,
	SQUAREMILLIMETERS,
	SQUAREMILES,
	SQUAREYARDS,
	SQUAREFEET,
	SQUAREINCHES
};
EnumParser<areaUnitEnum>::EnumParser()
{
	enumMap["squarekilometers"] = SQUAREKILOMETERS;
	enumMap["squaremeters"] = SQUAREMETERS;
	enumMap["squarecentimeters"] = SQUARECENTIMETERS;
	enumMap["squaremillimeters"] = SQUAREMILLIMETERS;
	enumMap["squaremiles"] = SQUAREMILES;
	enumMap["squareyards"] = SQUAREYARDS;
	enumMap["squarefeet"] = SQUAREFEET;
	enumMap["squareinches"] = SQUAREINCHES;
}

enum buildingTypeEnum {
	AutomotiveFacility,
	ConventionCenter,
	Courthouse,
	DataCenter,
	DiningBarLoungeOrLeisure,
	DiningCafeteriaFastFood,
	DiningFamily,
	Dormitory,
	ExerciseCenter,
	FireStation,
	Gymnasium,
	HospitalOrHealthcare,
	Hotel,
	Library,
	Manufacturing,
	Motel,
	MotionPictureTheatre,
	MultiFamily,
	Museum,
	Office,
	ParkingGarage,
	Pententiary,
	PerformingArtsTheater,
	PoliceStation,
	PostOffice,
	ReligiousBuilding,
	Retail,
	SchoolOrUniversity,
	SingleFamily,
	SportsArena,
	TownHall,
	Transportation,
	Unknown
};

EnumParser<buildingTypeEnum>::EnumParser()
{
	enumMap["automotivefacility"] = AutomotiveFacility;
	enumMap["conventioncenter"] = ConventionCenter;
	enumMap["courthouse"] = Courthouse;
	enumMap["datacenter"] = DataCenter;
	enumMap["diningbarloungeorleisure"] = DiningBarLoungeOrLeisure;
	enumMap["diningcafeteriafastfood"] = DiningCafeteriaFastFood;
	enumMap["diningfamily"] = DiningFamily;
	enumMap["dormitory"] = Dormitory;
	enumMap["exercisecenter"] = ExerciseCenter;
	enumMap["firestation"] = FireStation;
	enumMap["gymnasium"] = Gymnasium;
	enumMap["hospitalorhealthcare"] = HospitalOrHealthcare;
	enumMap["hotel"] = Hotel;
	enumMap["library"] = Library;
	enumMap["manufacturing"] = Manufacturing;
	enumMap["motel"] = Motel;
	enumMap["motionpicturetheatre"] = MotionPictureTheatre;
	enumMap["multifamily"] = MultiFamily;
	enumMap["museum"] = Museum;
	enumMap["office"] = Office;
	enumMap["parkinggarage"] = ParkingGarage;
	enumMap["penitentiary"] = Pententiary;
	enumMap["performingartstheater"] = PerformingArtsTheater;
	enumMap["policestation"] = PoliceStation;
	enumMap["postoffice"] = PostOffice;
	enumMap["religiousbuilding"] = ReligiousBuilding;
	enumMap["retail"] = Retail;
	enumMap["schooloruniversity"] = SchoolOrUniversity;
	enumMap["singlefamily"] = SingleFamily;
	enumMap["sportsarena"] = SportsArena;
	enumMap["townhall"] = TownHall;
	enumMap["transportation"] = Transportation;
	enumMap["unknown"] = Unknown;
};

enum lengthUnitEnum {
	KILOMETERS,
	METERS,
	CENTIMETERS,
	MILLIMETERS,
	MILES,
	YARDS,
	FEET,
	INCHES
};
EnumParser<lengthUnitEnum>::EnumParser()
{
	enumMap["kilometers"] = KILOMETERS;
	enumMap["meters"] = METERS;
	enumMap["centimeters"] = CENTIMETERS;
	enumMap["millimeters"] = MILLIMETERS;
	enumMap["miles"] = MILES;
	enumMap["yards"] = YARDS;
	enumMap["feet"] = FEET;
	enumMap["inches"] = INCHES;
};

enum temperatureUnitEnum {
	F,
	C,
	K,
	R
};
EnumParser<temperatureUnitEnum>::EnumParser()
{
	enumMap["F"] = F;
	enumMap["C"] = C;
	enumMap["K"] = K;
	enumMap["R"] = R;
}

enum versionEnum {
	ZeroPointThreeFive,
	ZeroPointThreeSix,
	ZeroPointThreeSeven,
	FivePointZeroZero,
	FivePointZeroOne,
	FivePointOneZero,
	FivePointOneOne,
	FivePointOneTwo,
	FivePointOneThree
};
EnumParser<versionEnum>::EnumParser()
{
	enumMap["0.35"] = ZeroPointThreeFive;
	enumMap["0.36"] = ZeroPointThreeSix;
	enumMap["0.37"] = ZeroPointThreeSeven;
	enumMap["5.00"] = FivePointZeroZero;
	enumMap["5.01"] = FivePointZeroOne;
	enumMap["5.10"] = FivePointOneZero;
	enumMap["5.11"] = FivePointOneOne;
	enumMap["5.12"] = FivePointOneTwo;
	enumMap["5.13"] = FivePointOneThree;
}

enum volumeUnitEnum {
	CUBICKILOMETERS,
	CUBICMETERS,
	CUBICCENTIMETERS,
	CUBICMILLIMETERS,
	CUBICMILES,
	CUBICYARDS,
	CUBICFEET,
	CUBICINCHES
};
EnumParser<volumeUnitEnum>::EnumParser()
{
	enumMap["cubickilometers"] = CUBICKILOMETERS;
	enumMap["cubicmeters"] = CUBICMETERS;
	enumMap["cubiccentimeters"] = CUBICCENTIMETERS;
	enumMap["cubicmillimeters"] = CUBICMILLIMETERS;
	enumMap["cubicmiles"] = CUBICMILES;
	enumMap["cubicyards"] = CUBICYARDS;
	enumMap["cubicfeet"] = CUBICFEET;
	enumMap["cubicinches"] = CUBICINCHES;
};

class Area
{
public:
	void setValue(string uVal)
	{
		value = uVal;
	}
	string getValue()
	{
		return value;
	}
	void setAreaUnit(string units)
	{
		EnumParser<areaUnitEnum> e;
		areaUnits = e.ParseSomeEnum(units);
	}
	areaUnitEnum getAreaUnit()
	{
		return areaUnits;
	}
private:
	string value;
	areaUnitEnum areaUnits;
};

class ZipCodeOrPostalCode
{
public:
	void setValue(string uZip)
	{
		zipCode = uZip;
	}
	string getValue()
	{
		return zipCode;
	}
private:
	string zipCode; //possible, but complex enhancement, regex checking
};

class Latitude
{
public:
	void Set(string pvalue){
		value = pvalue;
	}
	const string Get()
	{
		return value;
	}
private:
	string value; //relatively simple enhancement Regex expressions to validate the string
};

class Longitude
{
public:
	void setValue(string pvalue){
		value = pvalue;
	}
	const string getValue()
	{
		return value;
	}
private:
	string value; //relatively simple enhancement Regex expressions to validate the string
};

class Name
{
public:
	void Set(string pname){
		name = pname;
	}
	const string Get()
	{
		return name;
	}
private:
	string name;
};

class Level
{
public:
	void setValue(string uValue)
	{
		value = uValue;
	}
	string getValue()
	{
		return value;
	}
	void setLengthUnits(string units)
	{
		EnumParser<lengthUnitEnum> e;
		lengthUnits = e.ParseSomeEnum(units);
	}
	lengthUnitEnum getLengthUnits()
	{
		return lengthUnits;
	}
private:
	string value;
	lengthUnitEnum lengthUnits;
};

class BuildingStorey
{
public:
	void setId(string uId)
	{
		id = uId;
	}
	string getId()
	{
		return id;
	}
	void setName(Name uName)
	{
		name = uName;
	}
	Name getName()
	{
		return name;
	}
	void setLevel(Level uLevel)
	{
		level = uLevel;
	}
	Level getLevel()
	{
		return level;
	}
private:
	string id;
	Name name;
	Level level;
};

class Location
{
public:
	void SetName(Name pname){
		name = pname;
	}
	Name GetName()
	{
		return name;
	}
	void SetLatitude(Latitude plat){
		latitude = plat;
	}
	Latitude GetLatitude()
	{
		return latitude;
	}

	void setLongitude(Longitude uLong)
	{
		longitude = uLong;
	}
	Longitude getLongitude()
	{
		return longitude;
	}

	void setZipCode(ZipCodeOrPostalCode uZip)
	{
		zip = uZip;
	}
	ZipCodeOrPostalCode getZipCode()
	{
		return zip;
	}

private:
	ZipCodeOrPostalCode zip; //required field 
	Name name;
	Latitude latitude;
	Longitude longitude;
	string cADModelAzimuth;
	string zipcodeOrPostalCode;
};

class Building
{
public:
	void setId(string bId)
	{
		id = bId;
	}
	string getId()
	{
		return id;
	}

	void setBuildingType(string uType)
	{
		EnumParser<buildingTypeEnum> e;
		type = e.ParseSomeEnum(uType);
	}
	buildingTypeEnum getBuildingType()
	{
		return type;
	}

	void setArea(Area uAre)
	{
		area = uAre;
	}
	Area getArea()
	{
		return area;
	}
	void setStorey(BuildingStorey uStorey)
	{
		storey = uStorey;
	}
private:
	Area area;
	string id; //required field
	buildingTypeEnum type; //required field
	BuildingStorey storey;
};

class Campus
{
public:
	void setId(string pid)
	{
		id = pid;
	}
	string getId()
	{
		return id;
	}

	void SetLocation(Location l)
	{
		location = l;
	}
	Location GetLocation()
	{
		return location;
	}

	void setBuilding(Building uBuild)
	{
		building = uBuild;
	}
	Building getBuilding()
	{
		return building;
	}
private:
	std::string id;
	Location location;
	Building building;
};

class gbXML {
public:

	gbXML()
	{
		//an empty constructor
	}
	gbXML(std::string version){
		//will allow a user to create a gbxml object depending on version that can later be serialized
	}

	gbXML(std::string filePath, std::string fileName)
	{
		//will allow a user to deserialize a gbxml object depending on version, which can then be modified and later serialized
	}

	int makegbxmlRapid(gbXML gb, string filePath)
	{
		//unwind the gbXML object as required
		EnumParser<versionEnum> ep = EnumParser<versionEnum>();
		string version = ep.GetString(gb.getVersion());
		const char *v2 = version.c_str();
		EnumParser<temperatureUnitEnum> te = EnumParser<temperatureUnitEnum>();
		string tempEnum = te.GetString(gb.getTempUnit());
		const char *te2 = tempEnum.c_str();
		//continue to make more as required, checking for required fields

		xml_document<> doc;
		xml_node<>* decl = doc.allocate_node(node_declaration);
		decl->append_attribute(doc.allocate_attribute("version", "1.0"));
		decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
		//make gbXML root
		xml_node<>* root = doc.allocate_node(node_element, "gbxml");
		root->append_attribute(doc.allocate_attribute("version", doc.allocate_string(v2)));
		root->append_attribute(doc.allocate_attribute("temperatureUnit", doc.allocate_string(te2)));
		doc.append_node(root);

		//make Campus child node
		//place if statement to check for existence of campus element prior to serialization
		xml_node<>* campus = doc.allocate_node(node_element, "Campus");
		campus->append_attribute(doc.allocate_attribute("id", doc.allocate_string(gb.getCampus().getId().c_str())));


		//place if statement to check for existence of location object prior to serialization
		xml_node<>* location = doc.allocate_node(node_element, "Location");

		//place if statement to check for the existence of a Name object prior to serialization
		xml_node<>* loc_name = doc.allocate_node(node_element, "Name");
		std::string nm = gb.getCampus().GetLocation().GetName().Get();
		loc_name->value(doc.allocate_string(nm.c_str()));

		//place if statement to check for existence of a Latitude object prior to serialization
		xml_node<>* lat = doc.allocate_node(node_element, "Latitude");
		std::string l = gb.getCampus().GetLocation().GetLatitude().Get();
		lat->value(doc.allocate_string(l.c_str()));

		xml_node<>* longitude = doc.allocate_node(node_element, "Longitude");
		std::string lo = gb.getCampus().GetLocation().getLongitude().getValue();
		longitude->value(doc.allocate_string(lo.c_str()));
		//append the nodes in reverse order, just for clarity
		location->append_node(longitude);
		location->append_node(lat);
		location->append_node(loc_name);

		xml_node<>* building = doc.allocate_node(node_element, "Building");
		building->append_attribute(doc.allocate_attribute("id", doc.allocate_string(gb.getCampus().getBuilding().getId().c_str())));
		xml_node<>* bArea = doc.allocate_node(node_element, "Area");
		bArea->value(doc.allocate_string(gb.getCampus().getBuilding().getArea().getValue().c_str()));

		building->append_node(bArea);

		campus->append_node(location);
		campus->append_node(building);
		root->append_node(campus);
		//write to file
		string xml_string;
		rapidxml::print(std::back_inserter(xml_string), doc);

		std::ofstream file_stored(filePath);
		file_stored << doc;
		file_stored.close();
		doc.clear();

		return 0;
	}

	//attribute getters and setters
	areaUnitEnum getAreaUnit()
	{
		return areaUnits;
	}

	void setAreaUnit(string units)
	{
		EnumParser<areaUnitEnum> e;
		areaUnits = e.ParseSomeEnum(units);
	}

	lengthUnitEnum getLengthUnit()
	{
		return lengthUnits;
	}

	void setLengthUnit(string units)
	{
		EnumParser<lengthUnitEnum> e;
		lengthUnits = e.ParseSomeEnum(units);
	}

	temperatureUnitEnum getTempUnit()
	{
		return temperatureUnits;
	}

	void setTemperatureUnits(string units)
	{
		EnumParser<temperatureUnitEnum> e;
		temperatureUnits = e.ParseSomeEnum(units);
	}

	bool getUseSIUnits()
	{
		return useSIUnitsForResults;
	}

	void setUseSIUnits(bool useSI)
	{
		useSIUnitsForResults = useSI;
	}

	versionEnum getVersion()
	{
		return version;
	}

	void setVersion(string versionString)
	{
		EnumParser<versionEnum> e;
		version = e.ParseSomeEnum(versionString);
	}

	volumeUnitEnum getVolumeUnit()
	{
		return volumeUnits;
	}

	void setVolumeUnits(string units)
	{
		EnumParser<volumeUnitEnum> e;
		volumeUnits = e.ParseSomeEnum(units);
	}

	void setCampus(Campus c)
	{
		campus = c;
	}

	Campus getCampus()
	{
		return campus;
	}
private:
	std::string id;
	std::string engine;
	temperatureUnitEnum temperatureUnits;
	lengthUnitEnum lengthUnits;
	areaUnitEnum areaUnits;
	volumeUnitEnum volumeUnits;
	versionEnum version;
	bool useSIUnitsForResults;
	Campus campus;

};