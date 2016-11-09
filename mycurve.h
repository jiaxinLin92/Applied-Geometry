/**********************************************************************************
**
** Copyright (C) 1994 Narvik University College
** Contact: GMlib Online Portal at http://episteme.hin.no
**
** This file is part of the Geometric Modeling Library, GMlib.
**
** GMlib is free software: you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** GMlib is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with GMlib.  If not, see <http://www.gnu.org/licenses/>.
**
**********************************************************************************/


#ifndef MYCURVE_H
#define MYCURVE_H
/*! \file gmpcircle.h
 *
 *  Interface for the Mycurve class.
 */



#include "C:\quadcopter\gmlib\modules\parametrics\src\gmpcurve.h"

using namespace GMlib;



//  template <typename float>
  class Mycurve : public GMlib::PCurve<float,3> {
    GM_SCENEOBJECT(Mycurve)
  public:
    Mycurve( float radius = float(20) );
    Mycurve( const Mycurve& copy );
    virtual ~Mycurve();

    float               getRadius();
    bool            isClosed() const;
    void            setRadius( float radius = float(20) );


  protected:
    float               _r;

    void	          eval(float t, int d, bool l);
    float               getEndP();
    float               getStartP();

  }; // END class Mycurve

// Include Mycurve class function implementations
//#include "gmpcircle.c"


#endif
