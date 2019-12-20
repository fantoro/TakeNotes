// Header file
#include "NoteRefFilter.h"

// System libraries
#include <String.h>
#include <Entry.h>
#include <MimeType.h>

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
	if(entry.InitCheck() != B_OK)
		return false;

	// Return true if the file is a directory
	if (entry.IsDirectory())
		return true;

	// Get an entry_ref from entry
	entry_ref fRef;
	if(entry.GetRef(&fRef) != B_OK)
		return false;

	// Create a BMimeType object to hold the MIME type
	BMimeType m;

	// Guess the MIME type and store it in m
	if(BMimeType::GuessMimeType(&fRef, &m) != B_OK)
		return false;

	// Return true if the MIME type matches
	if (m == "application/takenotes")
		return true;

	// Filter the file out if it doesn't match any of the above
	return false;
}
