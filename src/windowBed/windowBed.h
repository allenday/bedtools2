/*****************************************************************************
  windowBed.h

  (c) 2009 - Aaron Quinlan
  Hall Laboratory
  Department of Biochemistry and Molecular Genetics
  University of Virginia
  aaronquinlan@gmail.com

  Licenced under the GNU General Public License 2.0+ license.
******************************************************************************/
#ifndef WINDOWBED_H
#define WINDOWBED_H

#include "bedFile.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//************************************************
// Class methods and elements
//************************************************
class BedWindow {

public:

	// constructor 
	BedWindow(string &bedAFile, string &bedBFile, int &leftSlop, int &rightSlop, bool &anyHit, bool &noHit, 
			  bool &writeCount, bool &strandWindows, bool &matchOnStrand);

	// destructor
	~BedWindow(void);
		
private:

	string _bedAFile;
	string _bedBFile;
	bool _anyHit;
	bool _writeCount;
	int _leftSlop;
	int _rightSlop;
	bool _noHit;
	bool _strandWindows;
	bool _matchOnStrand;

	// instance of a bed file class.
	BedFile *_bedA, *_bedB;
	
	// methods
	void WindowIntersectBed();
	void FindWindowOverlaps(BED &a, vector<BED> &hits);

};
#endif /* WINDOWBED_H */
