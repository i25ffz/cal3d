//****************************************************************************//
// submesh.h                                                                  //
// Copyright (C) 2001, 2002 Bruno 'Beosil' Heidelberger                       //
//           (C) 2002 Laurent 'Maxun' Desmecht                                //
//****************************************************************************//
// This library is free software; you can redistribute it and/or modify it    //
// under the terms of the GNU Lesser General Public License as published by   //
// the Free Software Foundation; either version 2.1 of the License, or (at    //
// your option) any later version.                                            //
//****************************************************************************//

#ifndef CAL_SUBMESH_H
#define CAL_SUBMESH_H

//****************************************************************************//
// Includes                                                                   //
//****************************************************************************//

#include "global.h"
#include "vector.h"

//****************************************************************************//
// Forward declarations                                                       //
//****************************************************************************//

class CalCoreSubmesh;

//****************************************************************************//
// Class declaration                                                          //
//****************************************************************************//

 /*****************************************************************************/
/** The submesh class.
  *****************************************************************************/

class CAL3D_API CalSubmesh
{
// misc
public:
  /// The submesh PhysicalProperty.
  typedef struct
  {
    CalVector position;
    CalVector positionOld;
    CalVector force;
  } PhysicalProperty;

  /// The submesh Face.
  typedef struct
  {
#ifdef CAL_16BIT_INDICES
    unsigned short vertexId[3];
#else
    int vertexId[3];
#endif
  } Face;

// member variables
protected:
  CalCoreSubmesh *m_pCoreSubmesh;
  std::vector<CalVector> m_vectorVertex;
  std::vector<CalVector> m_vectorNormal;
  std::vector<Face> m_vectorFace;
  std::vector<PhysicalProperty> m_vectorPhysicalProperty;
  int m_vertexCount;
  int m_faceCount;
  int m_coreMaterialId;
  bool m_bInternalData;

// constructors/destructor
public:
  CalSubmesh();
  virtual ~CalSubmesh();

// member functions	
public:
  bool create(CalCoreSubmesh *pCoreSubmesh);
  void destroy();
  CalCoreSubmesh *getCoreSubmesh();
  int getCoreMaterialId();
  int getFaceCount();
#ifdef CAL_16BIT_INDICES
  int getFaces(unsigned short *pFaceBuffer);
#else
  int getFaces(int *pFaceBuffer);
#endif

  std::vector<CalVector>& getVectorNormal();
  std::vector<PhysicalProperty>& getVectorPhysicalProperty();
  std::vector<CalVector>& getVectorVertex();
  int getVertexCount();
  bool hasInternalData();
  void setCoreMaterialId(int coreMaterialId);
  void setLodLevel(float lodLevel);
};

#endif

//****************************************************************************//
