#include "pch.h"
#include "BarcodeReader.h"

using namespace Dynamsoft;
using namespace Platform;

BarcodeReader::BarcodeReader()
{
}

byte* GetPointerToPixelData(IBuffer^ pixelBuffer, unsigned int *length)
{
	if (length != nullptr)
	{
		*length = pixelBuffer->Length;
	}
	// Query the IBufferByteAccess interface.
	ComPtr<IBufferByteAccess> bufferByteAccess;
	reinterpret_cast<IInspectable*>(pixelBuffer)->QueryInterface(IID_PPV_ARGS(&bufferByteAccess));

	// Retrieve the buffer data.
	byte* pixels = nullptr;
	bufferByteAccess->Buffer(&pixels);
	return pixels;
}

Array<String^>^ BarcodeReader::DecodeFileStream(IBuffer ^ pixelBuffer)
{
	CBarcodeReader reader;
	reader.InitLicense("t0068NQAAACqUjZa21C+W7fRdPkf2FRFRr+QpfVC2tDsl/8t25TzYCNxl5s0OkuwFgEMGNfN95Z0HYQ55ROi1px9JqVAP7/c=");
	unsigned int length = 0;
	byte* buffer = GetPointerToPixelData(pixelBuffer, &length);
	int ret = reader.DecodeFileInMemory(buffer, length, "");
	STextResultArray *paryResult = NULL;
	reader.GetAllTextResults(&paryResult);

	Array<String^>^ results = ref new Array<String^>(paryResult->nResultsCount);
	for (int i = 0; i < paryResult->nResultsCount; ++i) {
		std::string s_str = std::string(paryResult->ppResults[i]->pszBarcodeText);
		std::wstring wid_str = std::wstring(s_str.begin(), s_str.end());
		const wchar_t* w_char = wid_str.c_str();
		results->set(i, ref new String(w_char));
	}

	return results;
}