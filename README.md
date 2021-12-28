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

	This library is incompatible with scangearmp2
       
```
;
; SANE Backend specification file
;
; It's basically emacs-lisp --- so ; indicates comment to end of line.
; All syntactic elements are keyword tokens, followed by a string or
;  keyword argument, as specified.
;
; :backend *must* be specified.
; All other information is optional (but what good is the file without it?).
;

:backend canon_pixma                 ; name of backend
;:version (external)             ; version of backend
:url https://github.com/Ordissimo/libmfp2-canon/blob/master/README.md     ; backend's web page
:comment External binary-only backend for Linux i386 and x86_64?. See the website for the latest release.



:devicetype :scanner               ; start of a list of devices....
                                   ; other types:  :stillcam, :vidcam,
                                   ;               :meta, :api

:mfg Canon                     ; name a manufacturer
:url https://www.canon.com/
:comment Multi Function Peripheral. External backend made by Canon.  Please check the Canon website and/or contact us if you have a Canon device not mentioned here.

## Add 2018
 XK80 series
 
 TS9580 series
 TS9500 series
  
 TS8280 series
 TS8230 series
 TS8200 series
 
 TS6280 series
 TS6230 series
 TS6200 series
 
 TR9530 series
 TR4500 series
 
 G3010 series
 G4010 series
 
 E4200 series
 
 LiDE 400
 LiDE 300

# Add before 2018
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

MX455 series
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

# Add 2019
G6000 series
G6080 series
TS5300 series
TS5380 series
TS6300 series
TS6380 series
TS7330 series
TS8300 series
TS8380 series
TS8330 series
XK60 series
TS6330 series
TS3300 series
E3300 series


#Add 2020
G7000 series
G7080 series
GM4000 series
GM4080 series


#Add Dec 2020
TS3400 series
E3400 series
TR7000 series
G2020 series
G3060 series
G2060 series
G3020 series
TS7430 series
XK90 series
TS8430 series
TR7600 series
TR8600 series
TR8630 series
TS6400 series
TS7400 series


#Add Dec 2021
GX6000 series
GX7000 series
TS5400 series

TS5350i series
G600 series
TS3500 series
TR4600 series
E4500 series
TR4700 series
XK500 series
TS8530 series
XK100 series
TS7530 series
TS7450i series

```
# ADVANTAGES

Better image quality than 'pixma' backend (with an output image size of 2480x3507 pixels) Usable in Wi-fi.

# STATE

Tested with sane 1.0.25 and 1.0.32 (may not work for lower versions)<br>
In Platen, the backend recognizes CARD, L_L, L_P, 4X6_L, 4X6_P, HAGAKI_L, HAGAKI_P, 2L_L, 2L_P, A5, B5, A4 and LETTER formats.<br>
In ADF, the backend recognizes A4 and LETTER formats.<br>
The scan works in color or in gray map.<br>
The resolution option allow to have a 75, 150, 300 or 600 quality for the output.<br>
The source option allow to chose between Platen, ADF and ADF Duplex, i don't have a means of detection, so it depends on the hardware.

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
wget https://gdlp01.c-wss.com/gds/8/0100011058/01/scangearmp2-4.20-1-deb.tar.gz
tar xvf scangearmp2-4.20-1-deb.tar.gz
arch="$(if [[ "$(uname -p)" = "x86_64" ]] ; then echo "amd64"; else echo "i386"; fi)"
dpkg -i scangearmp2-4.20-1-deb/packages/scangearmp2_4.20-1_${arch}.deb
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
wget https://github.com/Ordissimo/libmfp2-canon/releases/download/0.1/libmfp2-canon-0.1-1.src.rpm
rpm -ivh libmfp2-canon-0.1-1.src.rpm

####### or second solution:
cd ~/rpmbuild/SOURCES
git clone https://github.com/Ordissimo/libmfp2-canon.git
rm -rf libmfp2-canon/.git*
mv libmfp2-canon libmfp2-canon-0.1
tar czvf libmfp2-canon-0.1.orig.tar.gz libmfp2-canon-0.1
cp libmfp2-canon-0.1/libmfp2-canon.spec ../SPECS/
rm -rf libmfp2-canon-0.1
```
###### Get developement environnement :
```
cd /tmp
wget http://gdlp01.c-wss.com/gds/2/0100009932/01/scangearmp2-4.20-1-rpm.tar.gz
tar xvf scangearmp2-4.20-1-rpm.tar.gz
rpm -ivh scangearmp2-4.20-1-rpm/packages/scangearmp2-4.20-1.$(uname -p).rpm
rm -rf scangearmp2-4.20-1-rpm
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
# if CentOS7
rpm -i libmfp2-canon-0.1*.rpm
# else if Fedora 30
rpm -i */libmfp2-canon-0.1*.rpm
```

# LICENSE

## Licence of libmfp2-canon in : README
The following files are licensed under the terms of the GNU General Public License Ver. 2.0.
	

