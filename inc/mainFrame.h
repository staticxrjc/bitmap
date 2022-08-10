#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>
class Main : public wxFrame {
private:
	wxMenuBar* m_pMenuBar;
	wxMenu* m_pFileMenu, *m_pHelpMenu;

public:
    Main(const wxString& title);
    virtual ~Main();
};
#endif // MAIN_FRAME_H