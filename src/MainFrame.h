#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

class CMainFrame : public wxFrame
{
public:
	CMainFrame(const wxString& title);

private:
	void CreateMenuBar();
	void CreateButtons();
	void CreateGUIControls();

private:
	wxMenuBar* m_pMenuBar;

protected:
	//----------------------------------------------------
	// event handlers
	//----------------------------------------------------
	void OnFileOpen(wxCommandEvent &event);
	void OnQuit(wxCommandEvent& event);
	DECLARE_EVENT_TABLE();
	
};

#endif // __MAINFRAME_H__
