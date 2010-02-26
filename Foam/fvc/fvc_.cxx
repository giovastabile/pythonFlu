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
//  See https://csrcs.pbmr.co.za/svn/nea/prototypes/reaktor/pyfoam
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef fvc_cxx
#define fvc_cxx


//---------------------------------------------------------------------------
%include "src/OpenFOAM/fields/tmp/tmp_scalarField.cxx"

%include "src/finiteVolume/finiteVolume/fvc/fvcDdt.cxx"
%include "src/finiteVolume/finiteVolume/fvc/fvcD_Dt.cxx"
%include "src/finiteVolume/finiteVolume/fvc/fvcGrad.cxx"
%include "src/finiteVolume/finiteVolume/fvc/fvcDiv.cxx"
%include "src/finiteVolume/finiteVolume/fvc/fvcVolumeIntegrate.cxx"
%include "src/finiteVolume/finiteVolume/fvc/fvcSnGrad.cxx"
%include "src/finiteVolume/finiteVolume/fvc/fvcReconstruct.cxx"
%include "src/finiteVolume/finiteVolume/fvc/fvcMeshPhi.cxx"

%include "src/finiteVolume/interpolation/surfaceInterpolation/surfaceInterpolate.cxx"


//---------------------------------------------------------------------------
#endif
