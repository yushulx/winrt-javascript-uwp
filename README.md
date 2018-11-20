# Building UWP Barcode Reader with C++/WinRT and JavaScript
The sample demonstrates how to build a simple UWP Barcode Reader with C++/WinRT and JavaScript on Windows 10.

## Environment
* Windows 10
* Visual Studio 2017

## Usage
Get a free [trial license](https://www.dynamsoft.com/CustomerPortal/Portal/Triallicense.aspx).

Install [Dynamsoft Barcode Reader](https://www.dynamsoft.com/Downloads/Dynamic-Barcode-Reader-Download.aspx).

Add `<Dynamsoft Barcode Reader>\Components\C_C++\Redist\x86\DynamsoftBarcodeReaderx86.dll` to the project and set copy action "Copy always".

![DLL copy](https://www.codepool.biz/wp-content/uploads/2018/11/dll-copy.PNG)

Set the license in `BarcodeReader.cpp`:

```cpp
reader.InitLicense("t0068NQAAACqUjZa21C+W7fRdPkf2FRFRr+QpfVC2tDsl/8t25TzYCNxl5s0OkuwFgEMGNfN95Z0HYQ55ROi1px9JqVAP7/c=");
```

Build and run the app.

![UWP barcode reader](https://www.codepool.biz/wp-content/uploads/2018/11/uwp-barcode-reader.PNG)

## Blog
[Building UWP Barcode Reader with C++/WinRT and JavaScript](https://www.codepool.biz/uwp-barcode-reader-winrt-javascript.html)
