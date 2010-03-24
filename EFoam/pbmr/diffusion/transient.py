#!/usr/bin/env python

#--------------------------------------------------------------------------------------
## VulaSHAKA (Simultaneous Neutronic, Fuel Performance, Heat And Kinetics Analysis)
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
## See https://vulashaka.svn.sourceforge.net/svnroot/vulashaka/pyfoam
##
## Author : Alexey PETROV
##


#---------------------------------------------------------------------------
"""
Steady state solver to the multigroup neutron diffusion equation
"""

#--------------------------------------------------------------------------------------
def main_standalone( argc, argv, nuclear_solver_factory, temperature_solver_factory ):

    from Foam.OpenFOAM.include import setRootCase
    args = setRootCase( argc, argv )

    from Foam.OpenFOAM.include import createTime
    runTime = createTime( args )

    from Foam.OpenFOAM.include import createMesh
    mesh = createMesh( runTime )

    from Foam.OpenFOAM import Switch
    nuclCalc = nuclear_solver_factory( mesh, Switch( True ) )

    temCalc = temperature_solver_factory( mesh, Switch( True ) )

    keffRes = 0; temRes = 0

    print "Start of time-dependent calculation"
    
    runTime += runTime.deltaT()
    while not runTime.end() :
        print "Time =", runTime.timeName(), "\n"

        # Nuclear Calculation
        nuclCalc.storeOldTime()
        nuclRes = nuclCalc.solve()
        nuclCalc.writeScalars() # Write time-dependent scalar data to file
        
        # Temperature Calculation
        temRes = temCalc.solve()

        # Write restart data
        runTime.write();

        print "ExecutionTime =", runTime.elapsedCpuTime(), "s", \
              "  ClockTime =", runTime.elapsedClockTime(), "s", \
              "\n"

        runTime += runTime.deltaT()
        pass
    
    print "End\n"

    import os
    return os.EX_OK


#--------------------------------------------------------------------------------------
import sys, os
if __name__ == "__main__" :
    if len( sys.argv ) == 1 :
        sys.argv = [ __file__, "/scratch/petrova/diffusionFoam-run/oecd_simplified_2G", "oecd_simplified_2G" ]
        pass

    from EFoam.pbmr.diffusion import nuclearCalculation
    from EFoam.pbmr.diffusion import temperatureCalculation
    
    from EFoam.pbmr.diffusion.nuclear_solver import solver as nuclear_solver
    from EFoam.pbmr.diffusion.temperature_solver import solver as temperature_solver

    os._exit( main_standalone( len( sys.argv ), sys.argv, nuclear_solver, temperature_solver ) )
    pass

    
#--------------------------------------------------------------------------------------

