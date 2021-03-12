#include <windows.h>
#include <string.h>
#include "IPower.h"
#include "Factory.h"

volatile ULONG UCServer = 0;

int main(int argc, const char** argv) {

	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if (argc < 2) return 0;
	for (int i = 0; i < argc; i++) {
		if (_strcmpi(argv[i], "/Embedding") == 0 || _strcmpi(argv[i], "-Embedding") == 0) {
			DWORD factoryId;
			HRESULT result;
			Factory* factory = new Factory();
			factory->AddRef();
			result = CoRegisterClassObject(CLSID_Power, (IUnknown*)factory,
				CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE, &factoryId);

			if (SUCCEEDED(result)) {
				Sleep(5000);
			}

			while (UCServer > 1) {
				Sleep(1000);
			}
			CoRevokeClassObject(factoryId);
			factory->Release();
		}
	}

	CoUninitialize();

	return 0;
};