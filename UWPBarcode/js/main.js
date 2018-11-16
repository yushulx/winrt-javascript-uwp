var reader = new Dynamsoft.BarcodeReader();
function readBarcode() {
    var picker = new Windows.Storage.Pickers.FileOpenPicker();
    picker.ViewMode = Windows.Storage.Pickers.PickerViewMode.Thumbnail;
    picker.SuggestedStartLocation = Windows.Storage.Pickers.PickerLocationId.PicturesLibrary;
    picker.fileTypeFilter.append(".jpg");
    picker.fileTypeFilter.append(".jpeg");
    picker.fileTypeFilter.append(".png");

    picker.pickSingleFileAsync().then(function(file) {
        if (file != null) {
            Windows.Storage.FileIO.readBufferAsync(file).then(function (buffer) {
                let result = reader.decodeFileStream(buffer);
                document.getElementById('results').innerHTML = JSON.stringify(result);
            }
            );
        }
        else {
            document.getElementById('results').innerHTML = "Operation cancelled.";
        }
    });

}

document.getElementById('fileinput').addEventListener('click', readBarcode, false);

