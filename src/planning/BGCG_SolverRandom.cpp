/* This file is part of the Multiagent Decision Process (MADP) Toolbox. 
 *
 * The majority of MADP is free software released under GNUP GPL v.3. However,
 * some of the included libraries are released under a different license. For 
 * more information, see the included COPYING file. For other information, 
 * please refer to the included README file.
 *
 * This file has been written and/or modified by the following people:
 *
 * Frans Oliehoek 
 * Matthijs Spaan 
 *
 * For contact information please see the included AUTHORS file.
 */

#include "BGCG_SolverRandom.h"

#include <float.h>
#include <iostream>
#include <fstream>
#include "boost/make_shared.hpp"

#include "BayesianGameCollaborativeGraphical.h"

using namespace std;

//Default constructor
BGCG_SolverRandom::BGCG_SolverRandom(
    const boost::shared_ptr<const BayesianGameCollaborativeGraphical> &bgcg,
    size_t nrSolutions):
        BGCG_Solver(bgcg,  nrSolutions)
{
}

double BGCG_SolverRandom::Solve()
{
    double value = 0.0;
    for(Index i=0;i!=GetNrDesiredSolutions();++i)
    {
        //translate found configuration to jpol
        JPPV_sharedPtr temp = boost::dynamic_pointer_cast<JointPolicyPureVector>( GetNewJpol() );
        JPPV_sharedPtr jpolBG=boost::make_shared<JointPolicyPureVector>(*temp);
//        delete temp;
        jpolBG->RandomInitialization();

        //store the solution
        AddSolution(*jpolBG,value);
    }

    return(value);
}
