var arr2 = new Array(10);
var divArr = document.getElementById("arr");
var insertsortExp = document.getElementById("insertsort-exp");
var insertSort;
var i;
var j;
initInsertsort();

function initInsertsort(){
    randomize(arr2, 16);
    i = 0;
    j = 0;
  stop();
    insertSort = insertionSort(arr2);
  insertsortExp.innerHTML = "...";
    drawDivArr(divArr, arr2);
}


function drawDivArr(divArr, arr,j,k, txt){
    clearDivArr(divArr);
    for(var i = 0; i < arr.length; i++){
        var newDiv = document.createElement("div");
        newDiv.style.height = 10*arr[i]+30+"px";
        newDiv.style.width = "20px";
        newDiv.style.display = "inline-block";
        newDiv.style.margin = "0px 5px 0px 5px";
        newDiv.style.backgroundColor = "black";
        newDiv.style.position = "absoulute";
        newDiv.style.bottom = "0";
        newDiv.style.position = "relative";
        newDiv.style.verticalAlign ="bottom";
        newDiv.style.writingMode = "vertical-rl";
        newDiv.style.textOrientation = "upright";
        newDiv.style.overflow = "hidden";
        newDiv.innerHTML = "<font size='1px' color='white'>"+arr[i]+"</font>";
        if(i === j){
            newDiv.style.backgroundColor = "lightblue";
            newDiv.innerHTML = "<font size='1px' color='red'>"+arr[i]+ txt+"</font>";
            newDiv.firstChild.style.left = "1px";
            newDiv.firstChild.style.maxWidth = "1px";
        }
        newDiv.firstChild.style.position = "absolute";
        newDiv.firstChild.style.right = "5px";
        newDiv.firstChild.style.top = "0px";
        if(i === k){
            newDiv.style.backgroundColor = "lightgreen";
        }
        divArr.appendChild(newDiv);
    }
    divArr.style.width = arr.length*30 + "px";
} 

function clearDivArr(divArr){
    while(divArr.firstChild) divArr.removeChild(divArr.firstChild);
}

function* insertionSort(arr){
    var newElem = 0;
    for(i = 1; i < arr.length; i++){
        newElem = arr[i];
        var k = i;
        for(j = i-1; j >= 0; j--){
          drawDivArr(divArr, arr, k, j, " NewElem");
          yield;
            if(newElem < arr[j]){
            var dtxt = "Compare if <font color='#24e273'>Array["+j+"]</font> is greater than <font color='#4286f4'>Array["+(j+1)+"]</font>";
            insertsortExp.innerHTML = dtxt;
                yield;
                arr[j+1] = arr[j];
                arr[j] = newElem;
                drawDivArr(divArr ,arr, --k, j+1, " NewElem");
                yield;
            } 
        }
    }
}
