
#include "mycurve.h"
#include "C:\quadcopter\gmlib\modules\parametrics\src\gmpcurve.h"

#include <parametrics/gmptorus>


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



/*! \file gmpcircle.c
 *
 *  Implementation of the Mycurve template class.
 */

#include "mycurve.h"

//  template <typename float>
//  inline
  Mycurve::Mycurve( float radius ) {

    _r = radius;
    this->_dm = GM_DERIVATION_EXPLICIT;
  }


//  template <typename float>
//  inline
  Mycurve::Mycurve( const Mycurve& copy ) : PCurve<float,3>(copy) {}


//  template <typename float>
  Mycurve::~Mycurve() {}


//  template <typename float>
//  inline
  void Mycurve::eval( float t, int d, bool /*l*/ ) {

    this->_p.setDim( d + 1 );

    const float ct = _r * 16*sin(t)*sin(t)*sin(t);
    const float st = _r * 13*cos(t)-5*cos(2*t)-2*cos(3*t)-cos(4*t);

    this->_p[0][0] = ct;
    this->_p[0][1] = st;
    this->_p[0][2] = float(0);

    if( this->_dm == GM_DERIVATION_EXPLICIT ) {

      if( d > 0 ) {

        this->_p[1][0] = -st;
        this->_p[1][1] =  ct;
        this->_p[1][2] =  float(0);
      }

      if( d > 1 ) {

        this->_p[2][0] = -ct;
        this->_p[2][1] = -st;
        this->_p[2][2] =  float(0);
      }

      if( d > 2 ) {

        this->_p[3][0] =  st;
        this->_p[3][1] = -ct;
        this->_p[3][2] =  float(0);
      }

      if( d > 3 ) {

        this->_p[4][0] =  ct;
        this->_p[4][1] =  st;
        this->_p[4][2] =  float(0);
      }

      if( d > 4 ) {

        this->_p[5][0] = -st;
        this->_p[5][1] =  ct;
        this->_p[5][2] =  float(0);
      }

      if( d > 5 ) {

        this->_p[6][0] = -ct;
        this->_p[6][1] = -st;
        this->_p[6][2] =  float(0);
      }

      if( d > 6 ) {

        this->_p[7][0] =  st;
        this->_p[7][1] = -ct;
        this->_p[7][2] =  float(0);
      }
    }
  }



  float Mycurve::getEndP() {

    return float( M_2PI );
  }


//  template <typename float>
//  inline
  float Mycurve::getStartP() {

    return float(0);
  }


//  template <typename float>
//  inline
  float Mycurve::getRadius() {

    return _r;
  }


//  template <typename float>
//  inline
  bool Mycurve::isClosed() const {

    return true;
  }


//  template <typename float>
//  inline
  void Mycurve::setRadius( float radius ) {

      _r = radius;
  }


 // END namespace GMlib
