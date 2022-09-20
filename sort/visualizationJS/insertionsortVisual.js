var arr2 = new Array(10);
var divArr = document.getElementById("arr");
var insertsortExp = document.getElementById("insertsort-exp");
var insertSort;
var algos = document.getElementsByClassName("array-div");
var i;
var j;
initInsertsort();

function initInsertsort(){
    randomize(arr2, 500);
    i = 0;
    j = 0;
  stop();
    insertSort = insertionSort(arr2);
  insertsortExp.innerHTML = "...";
    drawDivArr(divArr, arr2);
}
function* insertionSort(arr){
    var newElem = 0;
    for(i = 1; i < arr.length; i++){
        newElem = arr[i];
        var k = i;
        for(j = i-1; j >= 0; j--){
            drawDivArr(divArr, arr, k, j, " New<br>Element");
          yield;
            if(newElem < arr[j]){
            var dtxt = "Compare if <font color='#24e273'>Array["+j+"]</font> is greater than <font color="+BLUE+">Array["+(j+1)+"]</font>";
            insertsortExp.innerHTML = dtxt;
                yield;
                arr[j+1] = arr[j];
                arr[j] = newElem;
                drawDivArr(divArr ,arr, --k, j+1, " New<br>Element");
                yield;
            } 
        }
    }
}
