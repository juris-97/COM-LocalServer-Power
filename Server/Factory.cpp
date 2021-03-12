#include "Factory.h"
#include "Power.h"


Factory::Factory() {
	InterlockedIncrement(&UCServer);
	m_ref = 0;
};


Factory::~Factory() {
	InterlockedDecrement(&UCServer);
};


HRESULT STDMETHODCALLTYPE Factory::QueryInterface(REFIID id, void** ptr) {
	if (ptr == NULL) return E_POINTER;
	*ptr = NULL;
	if (id == IID_IUnknown)* ptr = this;
	else if (id == IID_IClassFactory)* ptr = this;
	if (*ptr != NULL) { AddRef(); return S_OK; };
	return E_NOINTERFACE;
};


ULONG STDMETHODCALLTYPE Factory::AddRef() {
	return InterlockedIncrement(&m_ref);
};


ULONG STDMETHODCALLTYPE Factory::Release() {
	ULONG result = InterlockedDecrement(&m_ref);
	if (result == 0) delete this;
	return result;
};


HRESULT STDMETHODCALLTYPE Factory::LockServer(BOOL v) {
	if (v) InterlockedIncrement(&UCServer);
	else InterlockedDecrement(&UCServer);
	return S_OK;
};


HRESULT STDMETHODCALLTYPE Factory::CreateInstance(IUnknown* outer, REFIID iid, void** ptr) {
	Power* power;

	if (ptr == NULL) return E_POINTER;
	*ptr = NULL;
	if (iid != IID_IUnknown && iid != IID_IPower) return E_NOINTERFACE;
	power = new Power();
	if (power == NULL) return E_OUTOFMEMORY;
	HRESULT result = power->QueryInterface(iid, ptr);
	if (FAILED(result)) {
		delete power;
		*ptr = NULL;
	}
	return result;
};