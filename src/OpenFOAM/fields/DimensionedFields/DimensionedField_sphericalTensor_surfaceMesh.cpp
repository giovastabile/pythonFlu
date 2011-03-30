//  VulaSHAKA (Simultaneous Neutronic, Fuel Performance, Heat And Kinetics Analysis)
//  Copyright (C) 2009-2010 Pebble Bed Modular Reactor (Pty) Limited (PBMR)
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  See https://vulashaka.svn.sourceforge.net/svnroot/vulashaka
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef DimensionedField_sphericalTensor_surfaceMesh_cpp
#define DimensionedField_sphericalTensor_surfaceMesh_cpp


//---------------------------------------------------------------------------
%module "Foam.src.OpenFOAM.fields.DimensionedFields.DimensionedField_sphericalTensor_surfaceMesh";
%{
  #include "src/OpenFOAM/fields/DimensionedFields/DimensionedField_sphericalTensor_surfaceMesh.hpp"
%}

// Keep on corresponding "director" includes at the top of SWIG defintion file
%include "src/OpenFOAM/directors.hxx"
%include "src/finiteVolume/directors.hxx"


//---------------------------------------------------------------------------
%import "src/OpenFOAM/fields/DimensionedFields/DimensionedField.cpp"

%import "src/OpenFOAM/fields/Fields/sphericalTensorField.cxx"
%import "src/finiteVolume/surfaceMesh.hxx"

%ignore Foam::DimensionedField< Foam::sphericalTensor, Foam::surfaceMesh >::typeName;
%ignore Foam::DimensionedField< Foam::sphericalTensor, Foam::surfaceMesh >::debug;
%ignore Foam::DimensionedField< Foam::sphericalTensor, Foam::surfaceMesh >::T;

DIMENSIONED_FIELD_TEMPLATE_FUNC( sphericalTensor, surfaceMesh )

%template( DimensionedField_sphericalTensor_surfaceMesh ) Foam::DimensionedField< Foam::sphericalTensor, Foam::surfaceMesh >;


//---------------------------------------------------------------------------

#endif