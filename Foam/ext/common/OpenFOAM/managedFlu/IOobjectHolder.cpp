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
#ifndef IOobjectHolder_cpp
#define IOobjectHolder_cpp


//---------------------------------------------------------------------------
%{
  #include "Foam/ext/common/OpenFOAM/managedFlu/IOobjectHolder.hh"
%}


//---------------------------------------------------------------------------
%include "Foam/ext/common/managedFlu/commonHolder.hxx"

%include "Foam/ext/common/OpenFOAM/shared_ptr/shared_ptr_IOobject.hpp"

%import "Foam/ext/common/managedFlu/DependentHolder.cxx"

%include "IOobjectHolder.hpp"


//---------------------------------------------------------------------------
%feature( "pythonappend" ) Foam::IOobjectHolder::SMARTPTR_PYAPPEND_GETATTR( IOobjectHolder );

%extend Foam::IOobjectHolder
{
  SMARTPTR_EXTEND_ATTR( IOobjectHolder );
  HOLDERS_CALL_SHARED_PTR_EXTENSION( IOobject );
}


//--------------------------------------------------------------------------------------
#endif
