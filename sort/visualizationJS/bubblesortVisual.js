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

