/***************************************************************************
 *   Copyright (C) 2008 by Frans Schreuder                                 *
 *   usbpicprog.sourceforge.net                                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef MAIN_H
#define MAIN_H
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <wx/wxprec.h>
#include <wx/cmdline.h>
#include <wx/wx.h>
#include <iostream>
#include <cstdlib>

#include "uppmainwindow_callback.h"
#include "hardware.h"
#include "pictype.h"
#include "read_hexfile.h"

/*Implementation of main wxWidgets application, from 
 OnCmdLineParsed function, either the gui or the command line app 
 is created.*/
class UsbPicProg : public wxApp
{
  public:
    virtual bool OnInit();
	virtual int OnExit();
    virtual int OnRun();
    virtual void OnInitCmdLine(wxCmdLineParser& parser);
    virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
 
private:
    bool silent_mode;
	ReadHexFile* readHexFile;
	PicType* picType;
	Hardware* hardware;
};

DECLARE_APP(UsbPicProg)


/*Command line parameters and help text	 */
static const wxCmdLineEntryDesc g_cmdLineDesc [] =
{
     { wxCMD_LINE_SWITCH, wxT("h"), wxT("help"),    	wxT("displays help on the command line parameters"),wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
	 { wxCMD_LINE_OPTION, wxT("p"), wxT("pictype"), 	wxT("specify the pic type (eg -p=P18F2550)"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
     { wxCMD_LINE_SWITCH, wxT("s"), wxT("silent"),  	wxT("do not display the hex file") },
	 { wxCMD_LINE_SWITCH, wxT("w"), wxT("write"),  		wxT("write the device") },
	 { wxCMD_LINE_SWITCH, wxT("r"), wxT("read"),  		wxT("read the device") },
	 { wxCMD_LINE_SWITCH, wxT("v"), wxT("verify"),  	wxT("verify the device") },
	 { wxCMD_LINE_SWITCH, wxT("e"), wxT("erase"),  		wxT("bulk erase the device") },
	 { wxCMD_LINE_SWITCH, wxT("b"), wxT("blankcheck"),  wxT("blankcheck the device") },
	 { wxCMD_LINE_PARAM,  wxT("f"), wxT("file"),  		wxT("hexfile"),wxCMD_LINE_VAL_STRING,wxCMD_LINE_PARAM_OPTIONAL },
 
     { wxCMD_LINE_NONE }
};
#endif //MAIN_H
