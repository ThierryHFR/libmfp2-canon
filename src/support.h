/*
 *  ScanGear MP for Linux
 *  Copyright CANON INC. 2007-2020
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307, USA.
 *
 * NOTE:
 *  - As a special exception, this program is permissible to link with the
 *    libraries released as the binary modules.
 *  - If you write modifications of your own for these programs, it is your
 *    choice whether to permit this exception to apply to your modifications.
 *    If you do not wish that, delete this exception.
*/

#ifndef	_SUPPORT_H_
#define	_SUPPORT_H_

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <limits.h>

/*
	Standard gettext macros.
*/
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (PACKAGE, String)
#  define Q_(String) g_strip_context ((String), gettext (String))
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define Q_(String) g_strip_context ((String), (String))
#  define N_(String) (String)
#endif


#define	_SGMP_DEBUG
#define	_SGMP_DEBUG_VERBOSE_


/*
	Debug message macros.
*/
#ifndef DBGMSG
#ifdef _SGMP_DEBUG
/* debug message */
	#define DBGMSG(...) ( fprintf( stderr, "[%s] ", __func__ ), fprintf( stderr, ""__VA_ARGS__ ) )
#else
/* do nothing. */
	#define DBGMSG( x, ... )
#endif
#endif

/*
 	Public macros.
*/
#ifndef DEFTOSTR
	#define DEFTOSTR1(def) #def
	#define DEFTOSTR(def) DEFTOSTR1(def)
#endif

/*
 	Public types.
*/
typedef struct
{
	/* scan parameters */
	int			scan_scanmode;
	int			scan_source;
	int			scan_color;
	int			scan_size;

	int			scan_format;

	int			scan_result;
	int			scanning_page;
	char		file_path[ PATH_MAX ];

	int			scan_x;
	int			scan_y;
	int			scan_wx;
	int			scan_hy;
	int			scan_w;
	int			scan_h;
	int			scan_res;
	/* error */
	int			last_error_quit;
}SGMP_Data_Lite;


/*
 	Public enum.
*/

/* clicked button type */
enum{
	CIJSC_VALUE_OK = 0,
	CIJSC_VALUE_CANCEL,
};

/* scanmode list */
enum{
	CIJSC_SCANMODE_PLATEN = 0,
	CIJSC_SCANMODE_ADF_S,
	CIJSC_SCANMODE_ADF_D_L,
	CIJSC_SCANMODE_ADF_D_S,
};

/* select source list */
enum{
	CIJSC_SOURCE_DOCUMENT = 0,
	CIJSC_SOURCE_PHOTO,
};

/* color mode list */
enum{
	CIJSC_COLOR_COLOR = 0,
	CIJSC_COLOR_GRAY,
};

/* size list */
enum{
	CIJSC_SIZE_CARD = 0,
	CIJSC_SIZE_L_L,
	CIJSC_SIZE_L_P,
	CIJSC_SIZE_4X6_L,
	CIJSC_SIZE_4X6_P,
	CIJSC_SIZE_HAGAKI_L,
	CIJSC_SIZE_HAGAKI_P,
	CIJSC_SIZE_2L_L,
	CIJSC_SIZE_2L_P,
	CIJSC_SIZE_A5,
	CIJSC_SIZE_B5,
	CIJSC_SIZE_A4,
	CIJSC_SIZE_LETTER,
};

/* file format */
enum{
	CIJSC_FORMAT_JPEG = 0,
	CIJSC_FORMAT_PDF,
};

/* error dialog type */
enum{
	CIJSC_ERROR_DLG_QUIT_FALSE = 0,
	CIJSC_ERROR_DLG_QUIT_TRUE,
};


#endif	/*_SUPPORT_H_*/
