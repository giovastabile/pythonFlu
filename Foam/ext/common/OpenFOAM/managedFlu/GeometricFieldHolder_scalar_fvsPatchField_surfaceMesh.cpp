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
#ifndef GeometricFieldHolder_scalar_fvsPatchField_surfaceMesh_cpp
#define GeometricFieldHolder_scalar_fvsPatchField_surfaceMesh_cpp


//---------------------------------------------------------------------------
%{
  #include "Foam/ext/common/OpenFOAM/managedFlu/GeometricFieldHolder_scalar_fvsPatchField_surfaceMesh.hh"
%}


//---------------------------------------------------------------------------
%include "Foam/ext/common/finiteVolume/smart_tmp/smart_tmp_surfaceScalarField.cpp"

%include "Foam/ext/common/OpenFOAM/managedFlu/GeometricFieldHolder.hxx"

%include <surfaceFields.hpp>

%template ( GeometricFieldHolder_scalar_fvsPatchField_surfaceMesh ) Foam::GeometricFieldHolder< Foam::scalar, Foam::fvsPatchField, Foam::surfaceMesh >;

EXTEND_SURFACESCALARFIELDHOLDER;


//---------------------------------------------------------------------------
%feature( "pythonappend" ) Foam::GeometricFieldHolder< Foam::scalar, Foam::fvsPatchField, Foam::surfaceMesh >::SMARTPTR_PYAPPEND_GETATTR( GeometricFieldHolder_scalar_fvsPatchField_surfaceMesh );

%extend Foam::GeometricFieldHolder< Foam::scalar, Foam::fvsPatchField, Foam::surfaceMesh >
{
  SMARTPTR_EXTEND_ATTR( GeometricFieldHolder_scalar_fvsPatchField_surfaceMesh );
}


//--------------------------------------------------------------------------------------
#endif
