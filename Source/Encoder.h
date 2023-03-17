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

//struct for polygon triangle data (vertice indices)
struct PolygonData
{
	uint32_t Vertex1Index;
	uint32_t Vertex2Index;
	uint32_t Vertex3Index;
};

//struct that keeps all of the 3D mesh's data and to be written into binary file
struct ModelData
{
	std::string ModelName;
		
	std::map<VertexData, uint32_t> Vertices;  //uint - vertex unique index; VertexData - struct that keeps all recoded data on the specific vertice of the mesh

	std::vector<PolygonData> Polygons; //contains an array of structures, each containing three vertices' indices that form a triangle-polygon
};


//class that holds and manages 3D mesh data
class MeshDataHandler
{
private:
	
	ModelData MeshData;

public:
	
	VertexData MakeVertex(Vector _Position, Vector _Normal, double _U, double _V);

	void AddPolygon(VertexData _Vertex1, VertexData _Vertex2, VertexData _Vertex3);

	void SetMeshName(std::string _InName);

	const ModelData& GetMeshData() const { return MeshData; }
};

//class that can write\read 3D mesh data to\from the binary file
class MeshBinaryEncoder
{
private:

	ModelData LastOpenedMesh;

public:

	MeshBinaryEncoder() {};
		
	void WriteMeshToFile(const ModelData& MeshData, const std::string FileName);

	ModelData& ReadMeshFromFile(const std::string FileName);
	
};


