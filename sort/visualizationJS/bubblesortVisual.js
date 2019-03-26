var canvas = document.getElementById("bubblesort");
var dynamicText = document.getElementById("dynamic");
var arr1 = new Array(10);
var i = arr.length;
var j = 0;
var test;
var id;
const GREEN = "#24e273";
const BLUE = "#4286f4";

function drawDivArr(divArr, arr,j,k, txt){
    clearDivArr(divArr);
    var norm = normalize(arr);
    for(var i = 0; i < arr.length; i++){
        var newDiv = document.createElement("div");
        newDiv.style.height = 30+norm[i]*100+"px";
        newDiv.style.width = "9%";
        newDiv.style.display = "inline-block";
        newDiv.style.margin = "0px 1px 0px 1px";
        newDiv.style.backgroundColor = "black";
        newDiv.style.position = "absoulute";
        newDiv.style.boxShadow = "2px 2px 2px rgba(0,0,0,0.5)";
        newDiv.style.bottom = "0";
        newDiv.style.position = "relative";
        newDiv.style.verticalAlign ="bottom";
        newDiv.style.backgroundColor="#bad3fc";

        //newDiv.style.writingMode = "vertical-rl";
        newDiv.style.textOrientation = "upright";
        newDiv.style.overflow = "hidden";
        newDiv.innerHTML = "<font size='2px' color='black'>"+arr[i]+"</font><br>";
        if(i === j){
            newDiv.style.backgroundColor = BLUE;
            var text ="<font size='2px' color='black'>"+arr[i];
            if(txt) text+=txt;
            text+="</font>";
            newDiv.innerHTML = text;
        }
        if(i === k){
            newDiv.style.backgroundColor = GREEN;
        }
        divArr.appendChild(newDiv);
    }
    divArr.style.width = Math.max(...norm)*100+30;
} 

function clearDivArr(divArr){
    while(divArr.firstChild) divArr.removeChild(divArr.firstChild);
}

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

init();
function init(){
    randomize(arr1, 500);
    dynamicText.innerHTML = "...";
    i = arr.length;
    j = 0;
    stop();
    test = bubblesort(arr1);
    id = 0;
    drawDivArr(canvas, arr1);
}

function getMax(arr){
    var max = arr[0];
    for(var i = 0; i < arr.length; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}


function* bubblesort(arr){
    for(i = arr.length-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            drawDivArr(canvas, arr, j, j+1);
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
                drawDivArr(canvas, arr, j+1, j);
                yield;
            }
        }
    }
}

