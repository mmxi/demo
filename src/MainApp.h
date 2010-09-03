#ifndef __MAINAPP_H__
#define __MAINAPP_H__

class CMyApp : public wxApp
{
public:
	virtual bool OnInit();

private:
	wxLocale m_Locale;
};

DECLARE_APP(CMyApp)

#endif // __MAINAPP_H__
