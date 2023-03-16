#include <string>
#include <map>
#include <vector>

struct Vector
{
	int X;
	int Y;
	int Z;
};

struct VertexData
{	
	//vertice position in 3D space and its normal:
	Vector Position; 

	Vector Normal;

	//UV coordinates:
	double U;

	double V;
};

struct PolygonData
{
	uint32_t Vertex1Index;
	uint32_t Vertex2Index;
	uint32_t Vertex3Index;
};

struct ModelData
{
	std::string ModelName;
		
	std::map<uint32_t, VertexData> Vertices;  //uint - vertex unique index; VertexData - struct that keeps all recoded data on the specific vertice of the mesh

	std::vector<PolygonData> Polygons; //contains an array of structures, each containing three vertices' indices that form a triangle-polygon
};


class MeshBinaryEncoder
{
public:

	MeshBinaryEncoder() {};
		
	void WriteMeshToFile(const ModelData& MeshData, const std::string FileName);

	ModelData ReadMeshFromFile(const std::string FileName);
	
};


