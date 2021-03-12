#ifndef FACTORY_H
#define FACTORY_H
#include <windows.h>

extern volatile ULONG UCServer;

class Factory : public IClassFactory
{

public:

	Factory();
	~Factory();
	virtual HRESULT STDMETHODCALLTYPE	QueryInterface(REFIID id, void** rv);
	virtual ULONG	STDMETHODCALLTYPE	AddRef();
	virtual ULONG	STDMETHODCALLTYPE	Release();
	virtual HRESULT STDMETHODCALLTYPE	LockServer(BOOL v);
	virtual HRESULT STDMETHODCALLTYPE	CreateInstance(IUnknown* outer, REFIID id, void** rv);

private:
	volatile ULONG m_ref;
};

#endif
