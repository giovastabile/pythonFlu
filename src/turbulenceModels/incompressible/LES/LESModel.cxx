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
//  See https://vulashaka.svn.sourceforge.net/svnroot/vulashaka/pyfoam
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#if ( __FOAM_VERSION__ < 010500 )
%include "src/common.hxx"
#define incompressibleLESModel_cxx
#endif


//-----------------------------------------------------------------------------
#ifndef incompressibleLESModel_cxx
#define incompressibleLESModel_cxx

//---------------------------------------------------------------------------
// Keep on corresponding "director" includes at the top of SWIG defintion file

%include "src/OpenFOAM/directors.hxx"

%include "src/finiteVolume/directors.hxx"


//----------------------------------------------------------------------------
%include "src/turbulenceModels/incompressible/turbulenceModel.cxx"

//#include "LESdelta.H"
//#include "fvm.H"
//#include "fvc.H"

%include "src/finiteVolume/fvMatrices/fvMatrices.cxx"

%include "src/transportModels/incompressible/transportModel.cxx"

// #include "wallFvPatch.H"

%include "src/finiteVolume/cfdTools/general/bound.cxx"

#include "src/OpenFOAM/fields/tmp/autoPtr.cxx"

//#include "runTimeSelectionTables.H"

%include "src/OpenFOAM/db/IOdictionary.cxx"


//----------------------------------------------------------------------------
#if ( __FOAM_VERSION__ == 010500 )
%{
    #include "LES/incompressible/LESModel/LESModel.H"
%}
#endif


#if ( __FOAM_VERSION__ >= 010600 )
%{
    #include "incompressible/LES/LESModel/LESModel.H"
%}
#endif


//----------------------------------------------------------------------------
%rename( incompressible_LESModel ) Foam::incompressible::LESModel;

%include "incompressible/LESModel.H"


//---------------------------------------------------------------------------
#endif
