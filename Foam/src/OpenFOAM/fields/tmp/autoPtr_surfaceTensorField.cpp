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
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef autoPtr_surfaceTensorField_cpp
#define autoPtr_surfaceTensorField_cpp


//---------------------------------------------------------------------------
%{
  #include "Foam/src/OpenFOAM/fields/tmp/autoPtr_surfaceTensorField.hh"
%}


//---------------------------------------------------------------------------
%import "Foam/src/OpenFOAM/fields/tmp/autoPtr.cxx"

%include "Foam/src/OpenFOAM/fields/GeometricFields/GeometricField_tensor_fvsPatchField_surfaceMesh.cpp"

AUTOPTR_TYPEMAP( Foam::surfaceTensorField );

%ignore Foam::autoPtr< Foam::surfaceTensorField >::operator->;

%template( autoPtr_surfaceTensorField ) Foam::autoPtr< Foam::surfaceTensorField >;

%feature( "pythonappend" ) Foam::autoPtr< Foam::surfaceTensorField >::SMARTPTR_PYAPPEND_GETATTR( autoPtr_surfaceTensorField );


//---------------------------------------------------------------------------
%extend Foam::autoPtr< Foam::surfaceTensorField > 
{
  SMARTPTR_EXTEND_ATTR( autoPtr_surfaceTensorField );
  SMARTPTR_EXTEND_OPERATOR_EQ( Foam::tensor );
}


//---------------------------------------------------------------------------
#endif
