## pythonFlu - Python wrapping for OpenFOAM C++ API
## Copyright (C) 2010- Alexey Petrov
## Copyright (C) 2009-2010 Pebble Bed Modular Reactor (Pty) Limited (PBMR)
## 
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
## 
## See http://sourceforge.net/projects/pythonflu
##
## Author : Alexey PETROV
##


#---------------------------------------------------------------------------
def CourantNo_010401_dev( mesh, phi, runTime ):
    from Foam.OpenFOAM import Time
    from Foam.finiteVolume import fvMesh
    from Foam.finiteVolume import surfaceScalarField

    CoNum = 0.0;
    meanCoNum = 0.0;

    if mesh.nInternalFaces() :
        from Foam import fvc
        SfUfbyDelta = mesh.deltaCoeffs()*phi.mag()
        CoNum =  ( SfUfbyDelta / mesh.magSf() ).ext_max().value() * runTime.deltaT().value()
        meanCoNum = ( SfUfbyDelta.sum() / mesh.magSf().sum() ).value() * runTime.deltaT().value();
        pass

    from Foam.OpenFOAM import ext_Info, nl
    ext_Info() << "Courant Number mean: " << meanCoNum << " max: " << CoNum<< nl

    return CoNum, meanCoNum


#---------------------------------------------------------------------------------------------
def CourantNo_010500_dev( mesh, phi, runTime ):
    from Foam.OpenFOAM import Time
    from Foam.finiteVolume import fvMesh
    from Foam.finiteVolume import surfaceScalarField

    CoNum = 0.0
    meanCoNum = 0.0
    velMag = 0.0
    
    if mesh.nInternalFaces() :
        from Foam import fvc
        SfUfbyDelta = mesh.deltaCoeffs()*phi.mag()
        CoNum =  ( SfUfbyDelta / mesh.magSf() ).ext_max().value() * runTime.deltaT().value()
        meanCoNum = ( SfUfbyDelta.sum() / mesh.magSf().sum() ).value() * runTime.deltaT().value()
        velMag = ( phi.mag()/mesh.magSf() ).ext_max().value()
        pass

    from Foam.OpenFOAM import ext_Info, nl
    ext_Info() << "Courant Number mean: " << meanCoNum << " max: " << CoNum<<  " velocity magnitude: " << velMag << nl

    return CoNum, meanCoNum, velMag


#---------------------------------------------------------------------------------------------
def CourantNo_020000( mesh, phi, runTime ):
    from Foam.OpenFOAM import Time
    from Foam.finiteVolume import fvMesh
    from Foam.finiteVolume import surfaceScalarField

    CoNum = 0.0
    meanCoNum = 0.0
    from Foam.OpenFOAM import ext_Info, nl
    
    if mesh.nInternalFaces() :
        from Foam import fvc
        tmp = fvc.surfaceSum( phi.mag() )
        sumPhi = tmp.internalField()
        CoNum =  0.5 * ( sumPhi / mesh.V().field() ).gMax() * runTime.deltaTValue()
        meanCoNum =  0.5 * ( sumPhi.gSum() / mesh.V().field().gSum() ) * runTime.deltaTValue()
        pass

    
    ext_Info() << "Courant Number mean: " << meanCoNum << " max: " << CoNum << nl

    return CoNum, meanCoNum
