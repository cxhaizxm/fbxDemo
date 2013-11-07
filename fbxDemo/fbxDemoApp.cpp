#include "fbxDemoApp.h"
#include <fbxsdk.h>

fbxDemoApp::fbxDemoApp(void)
{
}


fbxDemoApp::~fbxDemoApp(void)
{
}

void fbxDemoApp::loadFromFBX(const char *filename)
{
  FbxManager* lSdkManager = FbxManager::Create();
  FbxIOSettings *ios = FbxIOSettings::Create(lSdkManager,IOSROOT);
  FbxImporter* lImporter = FbxImporter::Create(lSdkManager,"");
  if(!lImporter->Initialize(filename, -1, lSdkManager->GetIOSettings()))
  {
    printf("Call to FbxImporter::Initialize() failed.\n");
    printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
    exit(-1);
  }
  FbxScene* lScene = FbxScene::Create(lSdkManager,"myScene");
  lImporter->Import(lScene);
  lImporter->Destroy();

  FbxNode* lRootNode = lScene->GetRootNode();
  if(lRootNode)
  {
    // TODO: Traverse the scene

  }
  lSdkManager->Destroy();
}

void fbxDemoApp::traverseFBXNodes(FbxNode* node)
{
  const char* nodeName = node->GetName();

  // Get da transforms
  FbxDouble3 translation = node->LclTranslation.Get();
  FbxDouble3 rotation = node->LclRotation.Get();
  FbxDouble3 scaling = node->LclScaling.Get();

  // Determine # of children the node has
  int numChildren = node->GetChildCount();
  FbxNode* childNode = 0;
  for(int i = 0; i < numChildren; i++)
  {
    childNode = node->GetChild(i);
    FbxMesh* mesh = childNode->GetMesh();
    if(mesh != NULL)
    {
      // Get vertices from the mesh
      int numVertices = mesh->GetControlPointsCount();
      GLfloat* tempVerts = new GLfloat[numVertices*3];

      for(int j = 0; j < numVertices; j++)
      {
        FbxVector4 coord = mesh->GetControlPointAt(j);
        tempVerts[j*3 + 0] = (GLfloat)coord.mData[0];
        tempVerts[j*3 + 1] = (GLfloat)coord.mData[1];
        tempVerts[j*3 + 2] = (GLfloat)coord.mData[2];
      }
      this->setGeometry(tempVerts, numVertices);

      int numIndices = mesh->GetPolygonVertexCount();
      int* indices = mesh->GetPolygonVertices();
      this->setIndexBuffer((GLuint*)indices, numIndices);
    }
    this->traverseFBXNodes(childNode);
  } 
}

void fbxDemoApp::setGeometry(GLfloat* vertices, int num_vertices)
{
  this->vertex_data = vertices;
  this->num_vertices = num_vertices;
}

void fbxDemoApp::setIndexBuffer(GLuint* indices, int num_indices)
{
  this->vertex_indices = indices;
  this->num_indices = num_indices;
  glBindVertexArray(vao);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_vbo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(vertex_indices), vertex_indices, GL_STATIC_DRAW);
}

void fbxDemoApp::loadVBO()
{
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void fbxDemoApp::startup(void)
{
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vertex_vbo);
  glGenBuffers(1, &index_vbo);
}