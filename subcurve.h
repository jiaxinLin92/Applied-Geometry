
/*! \file gmpsubcurve.h
 *
 *  Interface for the PSurfCurve class.
 */

#ifndef __SUBCURVE_H__
#define __SUBCURVE_H__

#include "mycurve.h"

namespace GMlib {


  //template <typename fl>
  class Subcurve : public Mycurve {
    GM_SCENEOBJECT(Subcurve)
  public:
    Subcurve( PCurve<float,3>* c, float s, float e);
    Subcurve( PCurve<float,3>* c, float s, float e, float t);
    Subcurve( const Subcurve& copy );

    virtual ~Subcurve();

    // virtual functions from PSurf
    virtual bool            isClosed() const;
    // Local functions
    void                    togglePlot();

  protected:

    PCurve<float,3>*          _c;
    float                   _s;
    float                   _t;
    float                   _e;
    Vector<float,3>     _trans;

    // virtual functions from PSurf
    void                eval( float t, int d, bool l = false );
    float                   getEndP();
    float                   getStartP();

  private:

    // Local help functions
    void set(PCurve<float,3>* c, float s, float e, float t);

  }; // END class Subcurve

} // END namepace GMlib


// Include Subcurve class function implementations



#endif // __SUBCURVE_H__

