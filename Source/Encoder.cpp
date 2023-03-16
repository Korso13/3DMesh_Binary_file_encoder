#pragma once

#include "Encoder.h"
#include <iostream>
#include <fstream>

void MeshBinaryEncoder::WriteMeshToFile(const ModelData& MeshData, const std::string FileName)
{
	std::ofstream out(FileName, std::ios::binary);

	out.write((char*)&MeshData, sizeof(MeshData));
}

ModelData MeshBinaryEncoder::ReadMeshFromFile(const std::string FileName)
{
	return ModelData();
}
