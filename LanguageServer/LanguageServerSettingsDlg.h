#ifndef LANGUAGESERVERSETTINGSDLG_H
#define LANGUAGESERVERSETTINGSDLG_H
#include "UI.h"

class LanguageServerSettingsDlg : public LanguageServerSettingsDlgBase
{
public:
    LanguageServerSettingsDlg(wxWindow* parent);
    virtual ~LanguageServerSettingsDlg();

protected:
    virtual void OnAddServer(wxCommandEvent& event);
};
#endif // LANGUAGESERVERSETTINGSDLG_H