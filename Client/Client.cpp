#include <windows.h>
#include <stdio.h>
#include "IPower.h"

int main() {

	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	IPower* pow;
	HRESULT result = CoCreateInstance(CLSID_Power, NULL, CLSCTX_LOCAL_SERVER, IID_IPower, (void**)& pow);

	if (SUCCEEDED(result)) {
		printf("[Server loaded successfully]\n\n");

		int val = 5;
		printf("Val = %d\n", val);
		pow->power(&val);
		printf("pow(Val) = %d ", val);

		pow->Release();
	}
	else {
		printf("Can't take instance.");
	}

	CoUninitialize();

	return 0;
};
