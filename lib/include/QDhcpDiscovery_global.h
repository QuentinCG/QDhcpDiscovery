#ifndef QDHCPDISCOVERY_GLOBAL_H
#define QDHCPDISCOVERY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QDHCPDISCOVERY_LIBRARY)
#  define QDHCPDISCOVERYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QDHCPDISCOVERYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QDHCPDISCOVERY_GLOBAL_H
