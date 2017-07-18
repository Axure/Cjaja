//
// Created by freet on 2017/7/9.
//

#ifndef CAPPA_JAVA_HH
#define CAPPA_JAVA_HH

#define DEBUG
#ifndef NO_DEBUG

#include <iostream>

#define DEBUG_LOG(x) std::cout << "[" << FILE_NAME << "]: " << x << std::endl
#else
#define DEBUG_LOG(x)
#endif

#include <cstdint>

//#define abstract virtual
//
#define null NULL
//#define enum enum class
//
#define transient
#define interface class
//#define final const
//
#define boolean bool
using byte = int8_t;
//#define short int16_t
//#define short int16_t
//#define int int32_t
//#define long int64_t

#include <java/lang/Object.hh>
#include <java/lang/Array.hh>
#include <java/lang/System.hh>
#include <java/lang/Runnable.hh>
#include <java/lang/Integer.hh>
#include <java/lang/String.hh>
#include <java/lang/Cloneable.hh>
#include <java/lang/Math.hh>
#include <java/lang/NullPointerException.hh>


using namespace java::lang;
//#define public public:
//#define protected protected:
//#define private private:
//
//#define transient
//#define final const
#endif //CAPPA_JAVA_HH
