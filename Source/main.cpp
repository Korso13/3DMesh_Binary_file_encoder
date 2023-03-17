#include "Encoder.h"
#include <iostream>

int main()
{
    //small demo of the classes work

    //main class' object -> can read\write binary 3D mesh files
    MeshBinaryEncoder* MeshDataEncoder = new MeshBinaryEncoder;

    //3Dmesh data handler - holds all data on one 3D mesh; 
    //can produce Vertex data structs that will be used to form polygons; 
    //can write down polygons data without making vertice duplicates
    MeshDataHandler MeshData1;
   
    //make four different vertices
    VertexData Vertice1 = MeshData1.MakeVertex(Vector{ 0, 0, 0 }, Vector{ 0, 0, 0 }, 2, 2);
    VertexData Vertice2 = MeshData1.MakeVertex(Vector{ 1,3,0 }, Vector{ -1,0,-1 }, 2, 3);
    VertexData Vertice3 = MeshData1.MakeVertex(Vector{ 2,0,1 }, Vector{ 0,0,-1 }, 1, 3);
    VertexData Vertice4 = MeshData1.MakeVertex(Vector{ 1,2,1 }, Vector{ 1,1,1 }, 4, 5);

    //add two triangle poligons to the mesh; Only four vertices will be recorded
    MeshData1.AddPolygon(Vertice1, Vertice2, Vertice3);
    MeshData1.AddPolygon(Vertice1, Vertice2, Vertice4);

    //setting mesh name
    MeshData1.SetMeshName("Mesh");

    //write mesh data into a binary file called TestFile.mbd
    MeshDataEncoder->WriteMeshToFile(MeshData1.GetMeshData(), "TestFile.mbd");

    //read mesh data from teh same file
    ModelData ReadMeshData = MeshDataEncoder->ReadMeshFromFile("TestFile.mbd");

    //printing data from binary file to make sure it's intact and optimized
    std::cout << "3D Model name: " << ReadMeshData.ModelName << std::endl;
    for (const auto Vertex : ReadMeshData.Vertices)
    {
        std::cout << "Vertex index: " << Vertex.second << " Vertex position: X " << Vertex.first.Position.X << " Y " << Vertex.first.Position.Y << " Z " << Vertex.first.Position.Z << std::endl;
        std::cout << " Vertex normal: X " << Vertex.first.Normal.X << " Y " << Vertex.first.Normal.Y << " Z " << Vertex.first.Normal.Z << std::endl;
        std::cout << " Vertex U: " << Vertex.first.U << " Vertex V: " << Vertex.first.V << std::endl;
        std::cout << std::endl;
    }

    int i = 0;
    for (const auto Polygon : ReadMeshData.Polygons)
    {
        std::cout << "Polygon #" << ++i << " indices are: " << Polygon.Vertex1Index << ", " << Polygon.Vertex2Index << ", " << Polygon.Vertex3Index << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
