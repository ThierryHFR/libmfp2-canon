# libmfp2-canon
Sane backend 'canon_pixma' for CANON's scanners

# DESCRIPTION

	Because of changes in CANON's network communication protocols,some of CANON's scanner 
	became unsuported by sane.

	This backend is for making the CANON's scanners, using the new communication protocol,
	to be supported by sane and any of the frontends implementing sane. It reuse the free
	code of the scangearmp2 program to access to the scanners functionalities and 
	implementing the sane functions.

	We separated the code from the backend, to make it a library with only free code.

	This library is dependent on the scangearmp2 package provided by Canon.
	The current version is 3.50, the list of scanners supported is below.
	You can download the archive that contains the 32/64 bit driver here:
	  http://gdlp01.c-wss.com/gds/1/0100009111/01/scangearmp2-3.50-1-deb.tar.gz
       
```
TS9100 series
TS8100 series
TS6100 series
TR8500 series
TR7500 series
TS5100 series
TS3100 series
E3100 series
TS9180 series
TS8180 series
TS6180 series
TR8580 series
TS8130 series
TS6130 series
TR8530 series
TR7530 series
XK50 series
XK70 series

MG7500 series
MG6600 series
MG5600 series
MG2900 series
MB2000 series
MB2300 series
MB5000 series
MB5300 series
E460 series

MX490 series
E480 series

MG7700 series
MG6900 series
MG6800 series
MG5700 series
MG3600 series

G3000 series

TS9000 series
TS8000 series
TS6000 series
TS5000 series
MG3000 series
E470 series
G4000 series

MB2100 series
MB2700 series
MB5100 series
MB5400 series
```
# ADVANTAGES

Better image quality than 'pixma' backend (with an output image size of 2480x3507 pixels) Usable in Wi-fi.

# STATE

Tested with sane 1.0.25 and 1.0.27 (may not work for lower versions)
Currently the backend allow image in A4 format.
The scan works in color or in gray map.
The options are not well handled, so they might not work.
The color option allow to chose between color or graymap modes.
The resolution option allow to have a hight or low quality for the output.

# KNOWN PROBLEMS

When using xsane :
bug with the display of the selected color option (Fixed)

# REQUIREMENTS

Requirements for libmfp2-canon in : README

# INSTALLATION

## For debian systems :
###### Get sources :
```
git clone https://github.com/Ordissimo/libmfp2-canon.git
```
###### Get developement environnement :
```
apt-get update
apt-get install debhelper libusb-1.0-0-dev libtool-bin libjpeg-dev
# or, if failure, use:
apt-get install debhelper libusb-1.0-0-dev libtool libjpeg-dev
cd /tmp
wget http://gdlp01.c-wss.com/gds/1/0100009931/01/scangearmp2-3.70-1-deb.tar.gz
tar xvf scangearmp2-3.70-1-deb.tar.gz
arch="$(if [[ "$(uname -p)" = "x86_64" ]] ; then echo "amd64"; else echo "i386"; fi)"
dpkg -i scangearmp2-3.70-1-deb/packages/scangearmp2_3.70-1_${arch}.deb
cd -
```
###### Build Sources :
```
cd libmfp2-canon
debuild -tc
```
###### Install :
```
dpkg -i ../libmfp2-canon_0.1_amd64.deb
```

## For redhat systems :
###### Prepare system :
```
mkdir -p ~/rpmbuild/{BUILD,BUILDROOT,RPMS,SOURCES,SPECS,SRPMS}
```
###### Get sources :
```
####### first solution
https://github.com/Ordissimo/libmfp2-canon/releases/download/0.1/libmfp2-canon-0.1-1.src.rpm
rpm -ivh libmfp2-canon-0.1-1.src.rpm

####### or second solution:
cd ~/rpmbuild/SOURCES
git clone https://github.com/Ordissimo/libmfp2-canon.git
rm -rf libmfp2-canon/.git*
mv libmfp2-canon libmfp2-canon-0.1
tar czvf  libmfp2-canon-0.1.orig.tar.gz 
cp libmfp2-canon-0.1/libmfp2-canon.spec ../SPECS/
rm -rf libmfp2-canon-0.1
```
###### Get developement environnement :
```
cd /tmp
wget http://gdlp01.c-wss.com/gds/2/0100009932/01/scangearmp2-3.70-1-rpm.tar.gz
tar xvf scangearmp2-3.70-1-rpm.tar.gz
rpm -ivh scangearmp2-3.70-1-rpm/packages/scangearmp2-3.70-1.$(uname -p).rpm
rm -rf scangearmp2-3.70-1-rpm
yum install gcc make libjpeg-turbo-devel libusbx-devel libtool automake autoconf
```
###### Build Sources :
```
cd ~/rpmbuild/SPECS
rpmbuild -ba libmfp2-canon.spec
```
###### Install :
```
cd ~/rpmbuild/RPMS
rpm -i */libmfp2-canon-0.1*.rpm
```

# LICENSE

## Licence of libmfp2-canon in : README
The following files are licensed under the terms of the GNU General Public License Ver. 2.0.
	

