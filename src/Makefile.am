libsane_canon_pixmadir = $(libdir)/sane
libsane_canon_pixma_LTLIBRARIES = libsane-canon_pixma.la
libsane_canon_pixma_la_SOURCES = saneopts.h sane.h sanei_debug.h \
        sanei.h sanei_init_debug.c sanei_backend.h \
        canon_pixma.c canon_pixma.h errordlg.c errordlg.h \
        keep_setting.c canon_mfp_io.c cnmsstrings.h errors.h \
        keep_setting.h canon_mfp_tools.c file_control.c canon_mfp_tools.h \
        cnmsfunc.c cnmsfunc.h file_control.h support.h
libsane_canon_pixma_la_LDFLAGS = -version-info 1:0:0
libsane_canon_pixma_la_LIBADD = -lcncpmslld2 -lcncpnet2 -lcncpnet20 -lcncpnet30 -lpthread -ldl $(LIBUSB_1_0_LIBS)
libsane_canon_pixma_la_CFLAGS = $(LIBUSB_1_0_CFLAGS) -I$(top_srcdir)/include
