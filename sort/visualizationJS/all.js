var canvas = document.getElementById("bubblesort");
var dynamicText = document.getElementById("dynamic");
var ctx = canvas.getContext("2d");
var arr = new Array(10);
var i = arr.length;
var j = 0;
var test;
var id;
ctx.font = "12px serif";
init();
function randomize(arr, max){
    for(var i = 0; i < arr.length; i++){
        arr[i] = Math.floor(Math.random()*max);
    }
}

function normalize(arr){
    var norm = new Array(arr.length);
    let min = Math.min(...arr);
    let max = Math.max(...arr);
    arr.forEach(function(number, index){
        norm[index] = (number-min)/max;
    });
    return norm;
}


function auto(t){
  if(!id){
        id = setInterval(function(){
            t.next();
        }, 500);
  } else stop();
}

function stop(){
  clearInterval(id);
  id= 0;
}


function init(){
    randomize(arr, 16);
    dynamicText.innerHTML = "...";
    i = arr.length;
    j = 0;
    ctx.clearRect(0,0,canvas.width,canvas.height);
    canvas.width = 30*arr.length;
    canvas.height = getMax(arr)*10+30;
  stop(3);
  test = bubblesort(arr);
    id = 0;
    drawArr(arr,-1,-1);
}

function getMax(arr){
    var max = arr[0];
    for(var i = 0; i < arr.length; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

function drawArr(arr, k, j){
    for(var i = 0; i < arr.length; i++){
        ctx.fillStyle = "#000000"   
        if(i == k) ctx.fillStyle = "#24e273"
        if(i == j) ctx.fillStyle = "#4286f4"
        ctx.fillRect(5+30*i, getMax(arr)*10+30, 20, -(10+arr[i]*10));
        ctx.fillStype = "#000000";
        ctx.fillText(arr[i], 12+30*i, canvas.height - arr[i]*10-15);
    }
}


function* bubblesort(arr){
    ctx.clearRect(0,0,canvas.width,canvas.height);
    for(i = arr.length-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            drawArr(arr, j, j+1);
            var dtxt = "Compare if <font color='#24e273'>Array["+j+"]</font> is greater than <font color='#4286f4'>Array["+(j+1)+"]</font>";
            dynamicText.innerHTML = dtxt;
            yield;
            if(arr[j]>arr[j+1]){
                dtxt += " if TRUE then <font color='red'>SWAP'EM</font>";
                dynamicText.innerHTML = dtxt;
                yield;
                var tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                ctx.clearRect(0,0,canvas.width,canvas.height);
                drawArr(arr, j, j+1);
                yield;
                ctx.clearRect(0,0,canvas.width,canvas.height);
            }
        }
    }
}

var arr2 = new Array(10);
var divArr = document.getElementById("arr");
var insertsortExp = document.getElementById("insertsort-exp");
var insertSort;
var algos = document.getElementsByClassName("array-div");
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
        console.log(divArr.offsetHeight);
}

function drawDivArr(divArr, arr,j,k, txt){
    clearDivArr(divArr);
    var norm = normalize(arr);
    for(var i = 0; i < arr.length; i++){
        var newDiv = document.createElement("div");
        newDiv.style.height = 30+norm[i]*100+"px";
        newDiv.style.width = "30px";
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
var arr3 = new Array(10);
var divArrSel = document.getElementById("arrSel");
var selectSort;

initSelectsort();

function initSelectsort(){
    randomize(arr3, 16);
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

var arr4 = new Array(10);
var divArrShell = document.getElementById("arrShel");
var shellExp = document.getElementById("shellsort-exp");
var shellSort;
initShellsort();
function initShellsort(){
  randomize(arr4, 16);
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
var arr5 = new Array(10);
var divArrCount = document.getElementById("arrCount");
var divArrCountTmp = document.getElementById("arrCountTmp");
var tmpWrapper = document.getElementById("tmp-wrapper");
var countExp = document.getElementById("countingsort-exp");
var countingSort;
var min, max, tmp;

initCountingsort();

function getMin(arr){
    var min = arr[0];
    for(var i = 0; i < arr.length; i++){
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

function initCountingsort(){
    randomize(arr5, 12);
    countingSort = countingsort(arr5);
    max = getMax(arr5);
    min = getMin(arr5);
    tmp = new Array((max - min)+1).fill(0);
    tmpWrapper.style.width = ((max-min)+1)*30+"px";
    divArrCountTmp.style.marginBottom = "0px";
    tmpWrapper.style.marginBottom = "5px";
  countExp.innerHTML = "...";
  stop();
    drawDivArr(divArrCountTmp, tmp);
    drawDivArr(divArrCount, arr5);
}

function* countingsort(arr){
    var k = 0;
    for(var i = 0; i < arr.length; i++){
        tmp[arr[i]-min]++;
        var dtxt = "Increment <font color='#4286f4'>Temporary Array["+
            (arr[i]-min)+"]</font> to count occurence of <font color='#4286f4'> "+arr[i]+" </font> in array.";
        countExp.innerHTML = dtxt;
        drawDivArr(divArrCount, arr, i, -1, "");
        drawDivArr(divArrCountTmp, tmp, arr[i]-min, -1, "++");
        yield;
    }
    for(var i = min; i <= max; i++){
        while(tmp[i-min] > 0){
            drawDivArr(divArrCountTmp, tmp, i-min, -1, "");
            var dtxt = "Write <font color='#4286f4'> "+
            (min+i)+" </font> to array.";
            countExp.innerHTML = dtxt;
            arr[k++] = i;
            drawDivArr(divArrCount, arr, k-1, -1, "");
            yield;
            dtxt = "Decrement <font color='#4286f4'>Temporary Array["+
            (i-min)+"] </font> to array.";
            countExp.innerHTML = dtxt;
            tmp[i-min]--;
            drawDivArr(divArrCountTmp, tmp, i-min, -1, "");
            yield;
        }
        drawDivArr(divArrCount, arr, i-min, -1, "");
    }
}
