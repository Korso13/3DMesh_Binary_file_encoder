//#include <iostream>
//#include "stdint.h" // in8_t = char; int16_t = short int; int32_t = long (int); int64_t = long long;
#include "Encoder.h"
#include <string>

int main()
{
    
    MeshBinaryEncoder* MeshDataEncoder = new MeshBinaryEncoder;

    ModelData MeshData;

    //std::string FileName{"TestFile"};

    VertexData Vertice1;
 /*   VertexData Vertice2;
    VertexData Vertice3;
    VertexData Vertice4;*/

    Vertice1.Position = Vector{ 0, 0, 0 };
    Vertice1.Normal = Vector{ 0, 0, 0 };
    Vertice1.U = 2;
    Vertice1.V = 2;
   /* Vertice2.Position = MakeVector(1,3,0);
    Vertice2.Normal = MakeVector(-1,0,-1);
    Vertice2.U = 2;
    Vertice2.V = 3;
    Vertice3.Position = MakeVector(2,0,1);
    Vertice3.Normal = MakeVector(0,0,-1);
    Vertice3.U = 1;
    Vertice3.V = 3;
    Vertice4.Position = MakeVector(1,2,1);
    Vertice4.Normal = MakeVector(1,1,1);
    Vertice4.U = 4;
    Vertice4.V = 5;*/

    MeshData.Vertices.insert(std::pair<uint32_t, VertexData>(0, Vertice1));
    MeshData.Polygons.push_back(PolygonData{ 0, 0, 0 });
    

    //MeshData.Vertices.insert(std::pair<uint32_t, VertexData>(1, Vertice2));
    //MeshData.Vertices.insert(std::pair<uint32_t, VertexData>(2, Vertice3));
    //MeshData.Vertices.insert(std::pair<uint32_t, VertexData>(3, Vertice4));
    
   /* MeshData.Polygons.push_back(PolygonData(0,1,2));
    MeshData.Polygons.push_back(PolygonData(1,2,3));
    MeshData.Polygons.push_back(PolygonData(0,2,3));*/

    MeshData.ModelName = "Mesh";

    MeshDataEncoder->WriteMeshToFile(MeshData, "TestFile.mbd");

    return 0;
}
