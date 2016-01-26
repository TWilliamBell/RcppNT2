//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_BITWISE_FUNCTIONS_SCALAR_FIRSTBITSET_HPP_INCLUDED
#define BOOST_SIMD_BITWISE_FUNCTIONS_SCALAR_FIRSTBITSET_HPP_INCLUDED

#include <boost/simd/bitwise/functions/firstbitset.hpp>
#include <boost/simd/include/functions/scalar/bitwise_cast.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT         ( firstbitset_, tag::cpu_, (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {
    typedef typename dispatch::meta::as_integer<A0, unsigned>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return a0 & (~a0+One<result_type>());
    }
  };

  BOOST_DISPATCH_IMPLEMENT         ( firstbitset_, tag::cpu_, (A0)
                            , (scalar_< floating_<A0> >)
                            )
  {
    typedef typename dispatch::meta::as_integer<A0, unsigned>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return firstbitset(bitwise_cast<result_type>(a0));
    }
  };
} } }

#endif
