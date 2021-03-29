ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

AM_CPPFLAGS = \
-I$(top_srcdir)/frontend \
<<<<<<< HEAD
-I$(top_builddir)/cpp_out \
-I$(top_srcdir)/../include \
-I$(top_srcdir)/p4info \
-I$(top_builddir)/grpc_out
=======
-isystem $(top_builddir)/cpp_out \
-isystem $(top_builddir)/grpc_out
>>>>>>> dreibh/debian-ubuntu-packaging

if WITH_SYSREPO
AM_CPPFLAGS += -DWITH_SYSREPO
endif

AM_CXXFLAGS = -Wall -Werror -Wno-deprecated-declarations

lib_LTLIBRARIES = libpigrpcserver.la

libpigrpcserver_la_SOURCES = \
gnmi.h \
gnmi_dummy.cpp \
log.h \
pi_server.cpp \
shared_mutex.h \
uint128.h \
uint128.cpp \
pi_server_testing.h

if WITH_SYSREPO
libpigrpcserver_la_SOURCES += \
gnmi_sysrepo.cpp
endif

nobase_include_HEADERS = PI/proto/pi_server.h

libpigrpcserver_la_LIBADD = \
$(top_builddir)/frontend/libpifeproto.la \
$(top_builddir)/p4info/libpiconvertproto.la \
$(top_builddir)/libpiprotogrpc.la \
$(top_builddir)/libpiprotobuf.la \
<<<<<<< HEAD
$(top_builddir)/../src/libpip4info.la \
$(PROTOBUF_LIBS) $(GRPC_LIBS)
=======
$(PROTOBUF_LIBS) $(GRPC_LIBS) \
$(BOOST_THREAD_LIB) $(BOOST_SYSTEM_LIB)
>>>>>>> dreibh/debian-ubuntu-packaging
# causes issue with libpiproto as it includes a version of google.rpc.Status
# -lgrpc++_error_details
