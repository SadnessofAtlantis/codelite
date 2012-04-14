#include "svn_file_explorer_traverser.h"
#include "virtualdirtreectrl.h"

SvnFileExplorerTraverser::SvnFileExplorerTraverser(wxTreeCtrl *tree, const Map_t &files, size_t imgCount)
	: wxTreeTraverser(tree)
	, m_files(files)
	, m_imgCount(imgCount)
{
}

SvnFileExplorerTraverser::~SvnFileExplorerTraverser()
{
}

void SvnFileExplorerTraverser::OnItem(const wxTreeItemId& item)
{
	VdtcTreeItemBase * itemData = dynamic_cast<VdtcTreeItemBase*>(m_tree->GetItemData(item));
	if ( itemData ) {

		wxFileName filename;
		if(itemData->IsDir())
			filename = wxFileName(itemData->GetFullpath(), wxT(""));
		else
			filename = itemData->GetFullpath();
			
		if(!IsPathUnderSvn(filename.GetFullPath(), itemData->IsDir())) {

			if(itemData->IsDir() && filename.GetDirCount()) {
				
				// this directory is not under version control, however if the parent directory is under version control
				// force it to use the 'Unversioned' icon
				filename.RemoveLastDir();
				if(IsPathUnderSvn(filename.GetFullPath(), true)) {
					int itemIndx = itemData->GetIconId() == -1 ? -1 : m_imgCount + itemData->GetIconId() + (m_imgCount * SvnFileExplorerTraverser::Unversioned);
					m_tree->SetItemImage(item, itemIndx);
					m_tree->SetItemImage(item, itemIndx, wxTreeItemIcon_Selected);
					m_tree->SetItemImage(item, itemIndx, wxTreeItemIcon_SelectedExpanded);
				}
			}
			return;
		}

		Map_t::const_iterator iter = m_files.find(itemData->GetFullpath());
		if(iter != m_files.end()) {
			SvnFileInfo fi = iter->second;
			switch(fi.type) {
			case Modified:
			case Locked:
			case Unversioned:
			case Conflicted:
			case Deleted:
			case New: {
				// Example:
				// Modified - Folder:
				// Modified type => 1
				// m_imgCount  => 18
				// Folder icon => 1
				// Our goal is to get icon idx => 37
				// Modified range: 36 - 53 (18 icons) 36 => Root/Mod, 37 => Folder/Mod, 20 => ...
				// The target icon is: 18 + (1) + (1 * 18)
				int itemIndx = itemData->GetIconId() == -1 ? -1 : m_imgCount + itemData->GetIconId() + (m_imgCount * fi.type);
				m_tree->SetItemImage(item, itemIndx);
				m_tree->SetItemImage(item, itemIndx, wxTreeItemIcon_Selected);
				m_tree->SetItemImage(item, itemIndx, wxTreeItemIcon_SelectedExpanded);
				break;

			}
			case Ignored:
				// do nothing ... keep the current image
				break;
			case Ok:
			default: {
				int itemIndx = itemData->GetIconId() == -1 ? -1 : m_imgCount + itemData->GetIconId() + (m_imgCount * SvnFileExplorerTraverser::Ok);
				m_tree->SetItemImage(item, itemIndx);
				m_tree->SetItemImage(item, itemIndx, wxTreeItemIcon_Selected);
				m_tree->SetItemImage(item, itemIndx, wxTreeItemIcon_SelectedExpanded);
				break;

			}
			}
		} else {
			int itemIndx = itemData->GetIconId() == -1 ? -1 : m_imgCount + itemData->GetIconId() + (m_imgCount * SvnFileExplorerTraverser::Ok);
			m_tree->SetItemImage(item, itemIndx);
			m_tree->SetItemImage(item, itemIndx, wxTreeItemIcon_Selected);
			m_tree->SetItemImage(item, itemIndx, wxTreeItemIcon_SelectedExpanded);
		}
	}
}

bool SvnFileExplorerTraverser::IsPathUnderSvn(const wxString& path, bool isDir)
{
	wxFileName fn;

	if(isDir) {
		fn = wxFileName(path, wxT(""));

	} else {
		fn = path;
	}

	fn.AppendDir(wxT(".svn"));
	MapPaths_t::const_iterator iter = m_svnPaths.find(fn.GetPath());
	if(iter == m_svnPaths.end()) {
		bool exists = ::wxDirExists(fn.GetPath());
		m_svnPaths[fn.GetPath()] = exists;
		return exists;
	} else {
		return iter->second;
	}
}
