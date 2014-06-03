#ifndef _LLERROR__H_
#define _LLERROR__H_

#include <iostream>
#include <assert.h>
#define llerr std::cerr << "Error: "
#define llwarn std::cerr << "Warning: "
#define lldebug std::cerr << "Debug: "
#define llendl std::endl
#define LL_ERRS(x) std::cerr << x "Error: " << ": "
#define LL_WARNS(x) std::cerr << x "Warning: " << ": "
#define LL_DEBUGS(x) std::cerr << x "Warning: " << ": "
#define LL_ENDL std::endl
#define llassert assert
//#define LL_BAD_TEMPLATE_INSTANTIATION(type, msg) static_assert(false, msg)

#endif /* _LLERROR__H_ */
