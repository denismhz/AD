var arr3 = new Array(10);
var divArrSel = document.getElementById("arrSel");
var selectSort;

initSelectsort();

function initSelectsort(){
    randomize(arr3, 500);
    stop();
    selectSort = selectionSort(arr3);
    drawDivArr(divArrSel, arr3);
}

function* selectionSort(arr){
    var largest = 0;
    for(var i = arr.length-1; i >= 0; i--){
        for(var j = 1; j <= i; j++){
            drawDivArr(divArrSel, arr, largest, j, " Largest");
            yield;
            if(arr[largest] < arr[j]){
                largest = j;
            }
        }
        var tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        drawDivArr(divArrSel, arr, i, largest, " Largest");
        yield;
        largest = 0;
    }
}
