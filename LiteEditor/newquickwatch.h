///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Mar 19 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __newquickwatch__
#define __newquickwatch__

#include <wx/intl.h>

#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class NewQuickWatch
///////////////////////////////////////////////////////////////////////////////
class NewQuickWatch : public wxDialog 
{
	private:
	
	protected:
		wxTreeCtrl* m_treeCtrl;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseEvent( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnKeyDown( wxKeyEvent& event ){ event.Skip(); }
		virtual void OnExpandItem( wxTreeEvent& event ){ event.Skip(); }
		
	
	public:
		NewQuickWatch( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Display Variable"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxRESIZE_BORDER|wxSTAY_ON_TOP|wxRAISED_BORDER );
		~NewQuickWatch();
	
};

#endif //__newquickwatch__
