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
#ifndef fvMatrixFunctions_hxx
#define fvMatrixFunctions_hxx


//---------------------------------------------------------------------------
%include "Foam/ext/common/OpenFOAM/managedFlu/GeometricFieldHolders.cpp"

%define __COMMON_FVMATRIXHOLDER_TEMPLATE_FUNC__( Type )
{
  Foam::fvMatrixHolder< Type > __add__( const Foam::fvMatrixHolder< Type >& theArg ) const
  {
    return *self + theArg;
  }

  Foam::fvMatrixHolder< Type > __eq__( const Foam::GeometricFieldHolder< Type, Foam::fvPatchField, Foam::volMesh >& theArg ) const
  {
    return *self == theArg;
  }

  Foam::fvMatrixHolder< Type > __add__( const Foam::GeometricFieldHolder< Type, Foam::fvPatchField, Foam::volMesh >& theArg ) const
  {
    return *self + theArg;
  }


}
%enddef


//--------------------------------------------------------------------------------------
%define __VECTOR_FVMATRIXHOLDER_TEMPLATE_FUNC__
{
  Foam::fvMatrixHolder< Foam::vector > __sub__( const Foam::fvMatrixHolder< Foam::vector >& theArg ) const
  {
    return *self - theArg;
  }

  Foam::fvMatrixHolder< Foam::vector > __eq__( const Foam::fvMatrixHolder< Foam::vector >& theArg ) const
  {
    return *self == theArg;
  }
  
  
  
}
%enddef


//--------------------------------------------------------------------------------------
%define FVMATRIXHOLDER_TEMPLATE_FUNC( Type );
%extend Foam::fvMatrixHolder< Type >  __COMMON_FVMATRIXHOLDER_TEMPLATE_FUNC__( Type );
%inline
%{
  Foam::lduMatrix::solverPerformance solve( Foam::fvMatrixHolder< Type > fvm, const Foam::dictionary& solverControls )
  {
    return Foam::solve( fvm, solverControls );
  }

  Foam::lduMatrix::solverPerformance solve( Foam::fvMatrixHolder< Type > fvm )
  {
    return Foam::solve( fvm );
  }
%}
%enddef


//--------------------------------------------------------------------------------------
%define VECTOR_FVMATRIXHOLDER_TEMPLATE_FUNC
FVMATRIXHOLDER_TEMPLATE_FUNC( Foam::vector );
%extend Foam::fvMatrixHolder< Foam::vector > __VECTOR_FVMATRIXHOLDER_TEMPLATE_FUNC__;
%enddef


//--------------------------------------------------------------------------------------
%define SCALAR_FVMATRIXHOLDER_TEMPLATE_FUNC
FVMATRIXHOLDER_TEMPLATE_FUNC( Foam::scalar );
%enddef


//--------------------------------------------------------------------------------------
#endif
