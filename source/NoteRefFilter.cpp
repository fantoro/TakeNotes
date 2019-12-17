// Header file
#include "NoteRefFilter.h"

// System libraries
#include <String.h>

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
	
	// Return true if the file is a directory
	if (entry.IsDirectory())
		return true;
	
	// Create a new BString for mimeType
	BString m(mimeType);

	// Return true if the MIME type matches
	if (m == "application/takenotes"){
		return true;
	}

	// Filter the file out if it doesn't match any of the above
	return false;
}
