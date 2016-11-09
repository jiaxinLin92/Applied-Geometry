
#include "subcurve.h"
namespace GMlib {


  // Constructors and destructors
  //******************************

//  template <typename float>
//  inline
  Subcurve::Subcurve(PCurve<float,3>* c, float s, float e )
  {
    this->_dm = GM_DERIVATION_EXPLICIT;

    set(c, s, e, (e+s)/2);

    DVector<Vector<float,3> > tr = _c->evaluateParent(_t, 0);
    _trans = tr[0];
    this->translateParent( _trans );
  }


//  template <typename float>
//  inline
  Subcurve::Subcurve( PCurve<float,3>* c, float s, float e, float t )
  {
    this->_dm = GM_DERIVATION_EXPLICIT;

    set(c, s, e, t);

    DVector<Vector<float,3> > tr = _c->evaluateParent(_t, 0);
    _trans = tr[0];
    this->translateParent( _trans );
  }


//  template <typename float>
//  inline
  Subcurve::Subcurve( const Subcurve& copy ) : Mycurve( copy )
  {
    set(copy._c, copy._s, copy._e, copy._t);

    _trans = copy._trans;
  }


//  template <typename float>
  Subcurve::~Subcurve() {}


  // Virtual functions from PSurf
  //******************************

//  template <typename float>
  void Subcurve::eval( float t, int d, bool /*l*/ )
  {
    this->_p     = _c->evaluateParent(t , d);
    this->_p[0] -= _trans;
  }


//  template <typename float>
  float Subcurve::getStartP()
  {
    return _s;
  }


//  template <typename float>
  float Subcurve::getEndP()
  {
    return _e;
  }


//  template <typename float>
  bool Subcurve::isClosed() const
  {
    return false;
  }


  // Private help functions
  //*************************

//  template <typename float>
//  inline
  void Subcurve::set(PCurve<float,3>* c, float s, float e, float t)
  {
    _c = c;
    _s = s;
    _t = t;
    _e = e;
  }


} //

