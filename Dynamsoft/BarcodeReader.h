#pragma once
#include "DynamsoftBarcodeReader.h"

#include <wrl.h>
#include <robuffer.h>

using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Microsoft::WRL;
using namespace Platform;

namespace Dynamsoft
{
    public ref class BarcodeReader sealed
    {
    public:
        BarcodeReader();
		Array<String^>^ DecodeFileStream(IBuffer^ pixelBuffer);
    };
}
