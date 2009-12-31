#ifndef __svn_preferences_dialog__
#define __svn_preferences_dialog__

/**
@file
Subclass of SvnPreferencesDialogBase, which is generated by wxFormBuilder.
*/

#include "subversion2_ui.h"
class Subversion2;

/** Implementing SvnPreferencesDialogBase */
class SvnPreferencesDialog : public SvnPreferencesDialogBase
{
	Subversion2 *m_plugin;
protected:
	// Handlers for SvnPreferencesDialogBase events.
	void OnBrowseSvnExe    ( wxCommandEvent& event );
	void OnBrowseDiffViewer( wxCommandEvent& event );
	void OnBrowseSSHClient ( wxCommandEvent& event );
	void OnButtonOK        ( wxCommandEvent &event );
	void OnUseExternalDiffUI( wxUpdateUIEvent &event);
	void OnAddRevisionMacroUI( wxUpdateUIEvent& event );

protected:
	wxString DoGetExecutable(const wxString &basePath);

public:
	/** Constructor */
	SvnPreferencesDialog( wxWindow* parent, Subversion2 *plugin );
	virtual ~SvnPreferencesDialog();
};

#endif // __svn_preferences_dialog__
