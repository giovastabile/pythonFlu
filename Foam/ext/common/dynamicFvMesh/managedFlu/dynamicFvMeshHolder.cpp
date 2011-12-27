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
#ifndef dynamicFvMeshHolder_cpp
#define dynamicFvMeshHolder_cpp


//---------------------------------------------------------------------------
%{
  #include "Foam/ext/common/dynamicFvMesh/managedFlu/dynamicFvMeshHolder.hh"
%}


//---------------------------------------------------------------------------
%import "Foam/ext/common/managedFlu/commonHolder.hxx"

%include "Foam/ext/common/dynamicFvMesh/shared_ptr/shared_ptr_dynamicFvMesh.hpp"

%import "Foam/ext/common/managedFlu/DependentHolder.cxx"

%import "Foam/src/finiteVolume/fvMesh/fvMeshes.cxx"

%include <dynamicFvMeshHolder.hpp>


//---------------------------------------------------------------------------
%feature( "pythonappend" ) Foam::dynamicFvMeshHolder::SMARTPTR_PYAPPEND_GETATTR( dynamicFvMeshHolder );

%extend Foam::dynamicFvMeshHolder
{
  SMARTPTR_EXTEND_ATTR( dynamicFvMeshHolder );
  HOLDERS_CALL_SHARED_PTR_EXTENSION( dynamicFvMesh );
}

%extend Foam::dynamicFvMesh FUNCTION_HOLDER_EXTEND( Foam::dynamicFvMesh );


//--------------------------------------------------------------------------------------
#endif
