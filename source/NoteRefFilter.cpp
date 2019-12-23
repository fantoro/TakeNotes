// Header file
#include "NoteRefFilter.h"

// System libraries
#include <String.h>
#include <Entry.h>
#include <Node.h>
#include <NodeInfo.h>

// Constructor
NoteRefFilter :: NoteRefFilter() {
}

// Filter hook method
bool NoteRefFilter :: Filter(const entry_ref *ref,
			BNode *node,
			struct stat_beos *stat,
			const char *mimeType) {

	// Follow links
	BEntry entry(ref,true);
	if (entry.InitCheck() != B_OK)
		return false;

	// Return true if the file is a directory
	if (entry.IsDirectory())
		return true;

	// Create a BNode and a BNodeInfo to get the MIME type
	BNode n(&entry);
	if (n.InitCheck() != B_OK) 
		return false;
	BNodeInfo nodeInfo(&n);
	if (nodeInfo.InitCheck() != B_OK)
		return false;

	// Create a string to hold the MIME type
	BString m;

	// Lock the buffer's string to use with BNodeInfo::GetType
	char *mbuf = m.LockBuffer(B_MIME_TYPE_LENGTH);

	// Get MIME type
	nodeInfo.GetType(mbuf);

	// Unlock the string's buffer for use 
	m.UnlockBuffer();

	// Return true if the MIME type matches
	if (m == "application/takenotes")
		return true;

	// Filter the file out if it doesn't match any of the above
	return false;
}
