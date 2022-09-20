var arr4 = new Array(10);
var divArrShell = document.getElementById("arrShel");
var shellExp = document.getElementById("shellsort-exp");
var shellSort;
initShellsort();
function initShellsort(){
  randomize(arr4, 500);
  stop();
    shellSort = shellsort(arr4);
    //shellExp.innerHTML = "...";
    drawDivArr(divArrShell, arr4);
}

function* shellsort(arr){
    for(var gap = Math.floor(arr.length/2); gap > 0; gap/=2){
        gap = Math.floor(gap);
        for(var i = gap; i < arr.length; i++){
            var newElem = arr[i];
            var j = i;
            while(j >= gap && arr[j-gap] > newElem){
                drawDivArr(divArrShell, arr, i, j-gap, "");
                yield;
                arr[j] = arr[j-gap];
                drawDivArr(divArrShell, arr, i, j-gap, "");
                j -= gap;           
                yield;
            }
            arr[j] = newElem;
            drawDivArr(divArrShell, arr, j, j-gap, "");
            yield;
        }
    }
    drawDivArr(divArrShell, arr);
}
