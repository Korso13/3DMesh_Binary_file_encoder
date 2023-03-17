#pragma once

#include "Encoder.h"
#include <iostream>
#include <fstream>

//member-function to write 3D model data into the binary file
void MeshBinaryEncoder::WriteMeshToFile(const ModelData& MeshData, const std::string FileName)
{
	std::ofstream out(FileName, std::ios::binary);

	out.write((char*)&MeshData, sizeof(MeshData));
}

//member-function to read 3D model from the binary file
ModelData& MeshBinaryEncoder::ReadMeshFromFile(const std::string FileName)
{
	std::ifstream in(FileName, std::ios::binary);

	in.read((char*)&LastOpenedMesh, sizeof(LastOpenedMesh));

	return LastOpenedMesh;
}

//helper member function to create new vertices
VertexData MeshDataHandler::MakeVertex(Vector _Position, Vector _Normal, double _U, double _V)
{
	VertexData OutVertex;

	OutVertex.Position = _Position;
	OutVertex.Normal = _Normal;
	OutVertex.U = _U;
	OutVertex.V = _V;

	return OutVertex;
}

//memebr function to add a polygon to the 3D mesh; guaranteed to avoid duplicate vertices
void MeshDataHandler::AddPolygon(VertexData Vertex1, VertexData Vertex2, VertexData Vertex3)
{
	PolygonData NewPolygon;
	
	const auto InsResult1 = MeshData.Vertices.insert(std::pair<VertexData, uint32_t>(Vertex1, MeshData.Vertices.size()));
	const auto InsResult2 = MeshData.Vertices.insert(std::pair<VertexData, uint32_t>(Vertex2, MeshData.Vertices.size()));
	const auto InsResult3 = MeshData.Vertices.insert(std::pair<VertexData, uint32_t>(Vertex3, MeshData.Vertices.size()));

	//the first member of the return of map's insert() is an iterator to a record (be it new or existing one). 
	//Record's second member is the vertex's index used to render polygons.
	NewPolygon.Vertex1Index = InsResult1.first->second;
	NewPolygon.Vertex2Index = InsResult2.first->second;
	NewPolygon.Vertex3Index = InsResult3.first->second;

	MeshData.Polygons.push_back(NewPolygon);
}

//3D mesh name setter
void MeshDataHandler::SetMeshName(std::string _InName)
{
	MeshData.ModelName = _InName;
}

//needed for std::map with VertexData to work properly
bool operator<(const VertexData& Vertex1, const VertexData& Vertex2)
{
	if ((Vertex1.Position.X + Vertex1.Position.Y + Vertex1.Position.Z + Vertex1.Normal.X + Vertex1.Normal.Y + Vertex1.Normal.Z + Vertex1.U + Vertex1.V) <
		(Vertex2.Position.X + Vertex2.Position.Y + Vertex2.Position.Z + Vertex2.Normal.X + Vertex2.Normal.Y + Vertex2.Normal.Z + Vertex2.U + Vertex2.V))
		return true;
	else
		return false;
}
