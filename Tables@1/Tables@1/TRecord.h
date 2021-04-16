#pragma once
#include <iostream>
#include <string>
typedef std::string TKey;
//using namespace std;
class TTabRecord
{
protected:
	TKey Key;

	int* pValue;//////////////////

	virtual void Print(std::ostream& os) { os << Key << " " << *pValue; }//////////////

public:
	TTabRecord(TKey k = "", int* pVal = NULL) { Key = k; pValue = pVal; }

	void SetKey(TKey k) { Key = k; }

    TKey GetKey(void) { return Key; }

    void SetValuePtr(int* p) { pValue = p; }

	int* GetValuePtr(void) { return pValue; }

	virtual int** GetCopy();

	TTabRecord& operator=(TTabRecord& tr)
	{
		Key = tr.Key;
		pValue = tr.pValue;

		return *this;
	}

	virtual int operator=(const TTabRecord & tr) { return Key == tr.Key; }

	virtual int operator< (const TTabRecord & tr) { return Key > tr.Key; }

	virtual int operator> (const TTabRecord& tr) { return Key < tr.Key; }

	friend class TArrayTable;
};
typedef TTabRecord* PTTabRecord;