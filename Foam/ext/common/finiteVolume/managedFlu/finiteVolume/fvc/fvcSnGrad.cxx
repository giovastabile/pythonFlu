//  pythonFlu - Python wrapping for OpenFOAM C++ API
//  Copyright (C) 2010- Alexey Petrov
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
//  See http://sourceforge.net/projects/pythonflu
//
//  Author : Alexey PETROV, Andrey SIMURZIN


//---------------------------------------------------------------------------
#ifndef fvcSnGrad_cxx
#define fvcSnGrad_cxx


//---------------------------------------------------------------------------
%module "Foam.ext.common.finiteVolume.managedFlu.finiteVolume.fvc.fvcSnGrad"

%{
  #include "Foam/ext/common/finiteVolume/managedFlu/finiteVolume/fvc/fvcSnGrad.hh"
%}


//---------------------------------------------------------------------------
%import "Foam/src/finiteVolume/fvMesh/fvMeshes.cxx"


//---------------------------------------------------------------------------
%include <fvcSnGrad.hpp>


%define FVCHOLDER_SNGRAD_FUNC( Type )
{
   inline Foam::GeometricFieldHolder< Foam::Type, Foam::fvsPatchField, Foam::surfaceMesh > fvc_snGrad( 
     const Foam::GeometricFieldHolder< Foam::Type, Foam::fvPatchField, Foam::volMesh >& field )
   {
     return Foam::fvc::snGrad( field );
   }
   
   inline Foam::GeometricFieldHolder< Foam::Type, Foam::fvsPatchField, Foam::surfaceMesh > fvc_snGrad( 
     const Foam::GeometricFieldHolder< Foam::Type, Foam::fvPatchField, Foam::volMesh >& field, const Foam::word& name )
    
   {
     return Foam::fvc::snGrad( field );
   }
}
%enddef

//--------------------------------------------------------------------------------------
%inline FVCHOLDER_SNGRAD_FUNC( scalar );


//--------------------------------------------------------------------------------------
#endif
