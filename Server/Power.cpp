#include <windows.h>
#include <stdio.h>
#include "Power.h"


Power::Power() {
	InterlockedIncrement(&UCServer);
	m_ref = 0;
};


Power::~Power() {
	InterlockedDecrement(&UCServer);
};


HRESULT STDMETHODCALLTYPE Power::QueryInterface(REFIID iid, void** ptr) {
	if (ptr == NULL) return E_POINTER;
	*ptr = NULL;
	if (iid == IID_IUnknown)* ptr = this;
	else if (iid == IID_IPower)* ptr = this;
	if (*ptr != NULL) { AddRef(); return S_OK; };
	return E_NOINTERFACE;
};


ULONG STDMETHODCALLTYPE Power::AddRef() {
	return InterlockedIncrement(&m_ref);
};


ULONG STDMETHODCALLTYPE Power::Release() {
	ULONG result = InterlockedDecrement(&m_ref);
	if (result == 0) delete this;
	return result;
};


HRESULT STDMETHODCALLTYPE Power::power(int* val) {

	*val *= *val;
	return S_OK;
};