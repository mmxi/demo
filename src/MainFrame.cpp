/////////////////////////////////////////////////////////////////////////////
// Name:        src/MainFrame.cpp
// Purpose:     Life! dialogs
// Author:      Steven Wang, <cjdx4311@gmail.com>
// Modified by:
// Created:     Aug/2010
// RCS-ID:      $Id: dialogs.cpp 41883 2006-10-10 12:06:09Z ABX $
// Copyright:   (c) 2010, StevenWang
// Licence:     GPL
/////////////////////////////////////////////////////////////////////////////

// ==========================================================================
// headers, declarations, constants
// ==========================================================================

#include "../include/mmxi.h"
#include "../include/MainFrame.h"
#include "../include/xmlrpc++/XmlRpc.h"

using namespace XmlRpc;

// --------------------------------------------------------------------------
// resources
// --------------------------------------------------------------------------

#include "../resource/application.xpm"

// --------------------------------------------------------------------------
// constants
// --------------------------------------------------------------------------

// IDs for the controls and the menu commands
enum
{
	// listbox in samples dialog
	MENU_FILE_CHANGE_USER = 101, // 切换用户
};

// --------------------------------------------------------------------------
// event tables and other macros for wxWidgets
// --------------------------------------------------------------------------

// Event tables
BEGIN_EVENT_TABLE(CMainFrame, wxFrame)
	EVT_MENU (wxID_OPEN, CMainFrame::OnFileOpen)
	EVT_MENU (wxID_EXIT, CMainFrame::OnQuit)
END_EVENT_TABLE()


// ==========================================================================
// implementation
// ==========================================================================

// --------------------------------------------------------------------------
// CMainFrame
// --------------------------------------------------------------------------

CMainFrame::CMainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title,                 
			  wxDefaultPosition, wxDefaultSize,
			  wxDEFAULT_FRAME_STYLE | wxNO_FULL_REPAINT_ON_RESIZE)
{
	this->SetIcon(wxIcon(application_xpm));

	CreateGUIControls();
}

void CMainFrame::CreateGUIControls()
{
	CreateMenuBar();
	
	CreateButtons();	
}

void CMainFrame::CreateMenuBar()
{
	m_pMenuBar = new wxMenuBar();
	
	// 创建文件菜单
	wxMenu* menu = new wxMenu();
	menu->Append(wxID_OPEN, wxT("打开"));
	menu->Append(wxID_EXIT, wxT("退出"));
	m_pMenuBar->Append(menu, _("&File"));

	SetMenuBar(m_pMenuBar);
}

void CMainFrame::CreateButtons()
{
	// create staticbox
	//wxStaticBox* pStaticBox = new wxStaticBox(this, wxID_ANY, _T("A wxStaticBoxSizer") );
	// create staticsizer
	//wxStaticBoxSizer* pStaticBoxSizer = new wxStaticBoxSizer(pStaticBox, wxVERTICAL);

	//SetSizer(pStaticBoxSizer);
	
	// add button
	wxPanel* p = new wxPanel(this, wxID_ANY);
	wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );
	topsizer->Add( new wxButton(p, wxID_ANY, _("&OK")) );

	wxStaticBoxSizer* pSTBX = new wxStaticBoxSizer(new wxStaticBox(p, wxID_ANY, _("&Preferences")), wxHORIZONTAL);
	pSTBX->Add( new wxButton(p, wxID_ANY, _("&OK")) );
	pSTBX->Add( new wxButton(p, wxID_ANY, _("&OK")) );
	pSTBX->Add( new wxButton(p, wxID_ANY, _("&OK")) );
	topsizer->Add(pSTBX, 0, 1);

	p->SetSizer(topsizer);
}

// --------------------------------------------------------------------------
// event handlers
// --------------------------------------------------------------------------
void CMainFrame::OnFileOpen(wxCommandEvent &event)
{
	
	/*
	XmlRpcValue noArgs, result;
	std::string output = "";

	XmlRpcClient c("http://xmlrpc.localhost/server.php", 80);

	if (c.execute("rpc_server", "get", result))
	{
		output = result;
	}
	*/

	wxMessageBox(wxT("hello"));

}

void CMainFrame::OnQuit(wxCommandEvent& event)
{
	Close();
}