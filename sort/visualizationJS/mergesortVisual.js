var arr6 = new Array(10);
var divArrM = document.getElementById("first-step");
var mergeSort;
var step = 1;
var first = 1;
initMergesort();
function initMergesort(){
    randomize(arr6, 11);
    stop();
    first = 1;
    mergeSort = mergesort(arr6, 0, arr6.length-1, "", -1, step);
    drawDivArrM(divArrM, arr6, -1, -1, "", 0, arr6.length);
}

function drawDivArrM(divArr, arr,j,k, txt, start, end){
    for(var i = start; i < end; i++){
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
}
//@end length-1 @start 0
var id = "";
function* mergesort(arr, start, end, id, r, step){
    if(end - start < 1) {
        console.log("return");
        console.log(id);
        id+="l1";
        drawDivArrM(document.getElementById(id), arr, -1, -1,"", 0, end+1);
        console.log(id);
        yield;
        id = "";
        console.log(id);
        return;
    }
    if(!first){
            id += ""+ r + 1;
        console.log(id);

        ++step;
        drawDivArrM(document.getElementById(id), arr, -1, -1,"", 0, end+1);
    }
    first = 0;
    var mid = Math.floor(start+(end-start)/2);
    console.log(arr);
    console.log(start, end);
    yield;
    yield *mergesort(arr, start, mid, id, "l", step);
    yield *mergesort(arr, mid+1, end, id, "r", step);
    yield *merge(arr, start, mid, end);
}


function *merge(arr, start, mid, end){
    var i = start;
    var j = mid+1;
    var index = 0;
    var tmp = new Array(end-start+1);
    while(i <= mid && j <= end){
        if(arr[i] < arr[j])
            tmp[index++] = arr[i++];
        else
            tmp[index++] = arr[j++];
    }
    while(i <= mid){
        tmp[index++] = arr[i++];
    }
    while(j<= end)
        tmp[index++] = arr[j++];
    for(var i = start; i <= end; i++){
        arr[i] = tmp[i-start];
    }
}
