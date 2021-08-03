#include "GardenStruct.h"


GardenStruct::GardenStruct(const GardenDetails& details, const Flower& fl):
	garden{details},
	flower{fl}
{
}

GardenStruct::~GardenStruct()
{

}