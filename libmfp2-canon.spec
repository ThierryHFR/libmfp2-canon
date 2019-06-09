Name:           libmfp2-canon
Version:        0.1
Release:        1
Summary:        The backend sane for "scangearmp2"

License:        GPLv2+
URL:            https://github.com/Ordissimo/libmfp2-canon
Source0:        libmfp2-canon-%{version}.orig.tar.gz

BuildRequires:  autoconf
BuildRequires:  automake
BuildRequires:  libtool
BuildRequires:  libjpeg-turbo-devel
BuildRequires:  libusbx-devel
BuildRequires:  scangearmp2

Requires:  libjpeg-turbo
Requires:  libusbx
Requires:  scangearmp2
Requires:  sane-backends


%description


%package        devel
Summary:        Development files for %{name}
Requires:       %{name}%{?_isa} = %{version}-%{release}

%description    devel
The %{name}-devel package contains libraries and header files for
developing applications that use %{name}.


%prep
%setup -q


%build
%configure --disable-static
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
%make_install
find $RPM_BUILD_ROOT -name '*.la' -exec rm -f {} ';'


%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%doc
%{_libdir}/sane/*.so*
%{_sysconfdir}/sane.d/dll.d/mfp2

%changelog
