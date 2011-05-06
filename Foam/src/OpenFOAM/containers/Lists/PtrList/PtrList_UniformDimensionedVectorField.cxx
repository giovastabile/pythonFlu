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
%module "Foam.src.OpenFOAM.containers.Lists.PtrList.PtrList_UniformDimensionedVectorField";
%{
   #include "src/OpenFOAM/containers/Lists/PtrList/PtrList_UniformDimensionedVectorField.hh"
%}


//---------------------------------------------------------------------------
%import "src/common.hxx"

#if FOAM_VERSION( <, 010600 )
#define PtrList_UniformDimensionedVectorField_cxx
#endif


//---------------------------------------------------------------------------
#ifndef PtrList_UniformDimensionedVectorField_cxx
#define PtrList_UniformDimensionedVectorField_cxx


//---------------------------------------------------------------------------
%import "src/OpenFOAM/fields/UniformDimensionedFields/UniformDimensionedVectorField.cxx"

%import "src/OpenFOAM/fields/tmp/autoPtr_UniformDimensionedVectorField.cxx"

%import "src/OpenFOAM/containers/Lists/PtrList/PtrList.cxx"

%ignore Foam::PtrList< Foam::uniformDimensionedVectorField >::PtrList;
%ignore Foam::PtrList< Foam::uniformDimensionedVectorField >::begin;
%ignore Foam::PtrList< Foam::uniformDimensionedVectorField >::end;
%ignore Foam::PtrList< Foam::uniformDimensionedVectorField >::set;
%ignore Foam::PtrList< Foam::uniformDimensionedVectorField >::xfer;

%template( PtrList_uniformDimensionedVectorField ) Foam::PtrList< Foam::uniformDimensionedVectorField >;


//---------------------------------------------------------------------------
%extend Foam::PtrList< Foam::uniformDimensionedVectorField >
{
  Foam::PtrList< Foam::uniformDimensionedVectorField >( const Foam::label s )
  {
    return new Foam::PtrList< Foam::uniformDimensionedVectorField >( s );
  }
}

%extend Foam::PtrList< Foam::uniformDimensionedVectorField > PTRLISTBASED_ADDONS( Foam::uniformDimensionedVectorField )


//---------------------------------------------------------------------------
#endif
