add_library(sane-canon_pixma SHARED canon_pixma.c
                                    canon_mfp_io.c
                                    canon_mfp_tools.c
                                    cnmsfunc.c
                                    errordlg.c
                                    file_control.c
                                    keep_setting.c
                                    errordlg.c
           )
set_target_properties(sane-canon_pixma PROPERTIES
                      C_STANDARD 11
                      VERSION "1.0.0"
                      SOVERSION "1")

if(DEBUG)
  target_compile_definitions(sane-canon_pixma PRIVATE "_SGMP_DEBUG" "_SGMP_DEBUG_VERBOSE_")
  target_compile_options(sane-canon_pixma PRIVATE "-O0" "-ggdb3")
else(DEBUG)
  target_compile_options(sane-canon_pixma PRIVATE "-O2")
endif(DEBUG)

target_include_directories(sane-canon_pixma PRIVATE ${JPEG_INCLUDE_DIR} ${LIBUSB_INCLUDE_DIRS} ${SANE_INCLUDE_DIRS} ../include )
target_link_libraries(sane-canon_pixma pthread ${SANE_LIBRARIES} ${JPEG_LIBRARY} ${LIBUSB_LIBRARIES})
target_link_libraries(sane-canon_pixma cncpmslld2 cncpnet2 cncpnet20 cncpnet30)
target_compile_definitions(sane-canon_pixma PRIVATE "PACKAGE_DATA_DIR=\"../share/scangearmp2\"")
target_compile_definitions(sane-canon_pixma PRIVATE "CNMSLIBPATH=../${CMAKE_INSTALL_LIBDIR}/bjlib")
target_compile_definitions(sane-canon_pixma PRIVATE "ENABLE_NLS")


install(TARGETS sane-canon_pixma DESTINATION "${CMAKE_INSTALL_LIBDIR}/sane/")
