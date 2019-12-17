#ifndef NOTEREFFILTER_H
#define NOTEREFFILTER_H

// System libraries
#include <FilePanel.h>

// Definition of the class
class NoteRefFilter : public BRefFilter {

public:
			NoteRefFilter();
	
	bool		Filter(const entry_ref *ref,
				BNode *node,
				struct stat_beos *stat,
				const char *mimeType);
};

#endif
