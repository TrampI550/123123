#pragma once
#define ARRAYTAB_M
#include "TTable.h"
#define TabMaxSize 25
enum TDataPos{FIRST_POS,CURRENT_POS,LAST_POS};
class TArrayTable
{
protected:
	PTTabRecord* pRecs;
	int TabSize;
	int CurPos;
public:
	TArrayTable(int Size = TabMaxSize) : TabSize(Size)
	{
		pRecs = new PTTabRecord[TabSize];
		for (int i = 0; i < TabSize; i++)
		{
			pRecs[i] = NULL;
		}
		CurPos = 0;
	}
	virtual ~TArrayTable()
	{
		for (int i = 0; i < DataCount; i++)
			delete pRecs[i];
		delete[] pRecs;
	}
	virtual int IsFull() const
	{
		return DataCount >= TabSize;
	}
	int GetSize() const
	{
		return TabSize;
	}
	virtual TKey GetKey() const
	{
		return GetKey(CURRENT_POS);
	}
	virtual PTDatValue GetValuePtr() const
	{
		return GetValuePtr(CURRENT_POS);
	}
	virtual TKey GetKey(TDataPos mode) const;
	virtual int Reset();
	virtual int IsTableEnded() const;
	virtual int GoNext();
	virtual int SetCurrentPos(int pos);
	int GetCurrentPos() const
	{
		return CURRENT_POS;/////////////////////////////////////////////////
	}
};
