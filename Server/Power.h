#ifndef POWER_H
#define POWER_H

#include <windows.h>
#include "IPower.h"

extern volatile ULONG UCServer;

class Power : public IPower {

public:

	Power();
	~Power();
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID id, void** rv);
	virtual ULONG	STDMETHODCALLTYPE AddRef();
	virtual ULONG	STDMETHODCALLTYPE Release();
	virtual HRESULT STDMETHODCALLTYPE power(int* val);

private:
	volatile ULONG m_ref;
};

#endif