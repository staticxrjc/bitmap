 #include <mainFrame.h>
 
    Main::Main(const wxString& title)
		: wxFrame(NULL, wxID_ANY, title, wxPoint(10,10), wxSize(450, 350))
	{
		m_pMenuBar = new wxMenuBar();
		
		// File menu
		m_pFileMenu = new wxMenu();
		m_pFileMenu->Append(wxID_OPEN, _T("&Open"), _T("Opens an existing file"));
		m_pFileMenu->Append(wxID_SAVE, _T("&Save"), _T("Save the content"));
		m_pFileMenu->AppendSeparator();
		m_pFileMenu->Append(wxID_EXIT, _T("&Quit"), _T("Quit the application"));
		m_pMenuBar->Append(m_pFileMenu, _T("&File"));

		// About menu
		m_pHelpMenu = new wxMenu();
		m_pHelpMenu->Append(wxID_ABOUT, _T("&About"), _T("Shows information about the application"));
		m_pMenuBar->Append(m_pHelpMenu, _T("&Info"));

		SetMenuBar(m_pMenuBar);

		m_pMenuBar->Bind(wxEVT_MENU,[this](wxCommandEvent& p){
				std::cout << "Test: " << p.GetId() << std::endl;
			},wxID_OPEN);

		CreateStatusBar(3);
		SetStatusText(wxT("Ready"), 0);

		Centre();
	}
