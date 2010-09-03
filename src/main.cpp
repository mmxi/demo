#include "../include/mmxi.h"
#include "../include/MainFrame.h"
#include "../include/MainApp.h"

IMPLEMENT_APP(CMyApp)

bool CMyApp::OnInit()
{
	m_Locale.Init(wxLANGUAGE_CHINESE_SIMPLIFIED, wxLOCALE_CONV_ENCODING);
	//m_Locale.Init(wxLANGUAGE_ENGLISH, wxLOCALE_CONV_ENCODING);

	m_Locale.AddCatalogLookupPathPrefix(wxT("../locale"));

	m_Locale.AddCatalog(wxT("zh_CN"));

	CMainFrame* frame = new CMainFrame(_("MyShopAssistant"));

	frame->Show();

	SetTopWindow(frame);

	return true;
}
