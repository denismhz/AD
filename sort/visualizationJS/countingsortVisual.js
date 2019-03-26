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
    randomize(arr5, 10);
    countingSort = countingsort(arr5);
    max = getMax(arr5);
    min = getMin(arr5);
    tmp = new Array((max - min)+1).fill(0);
    //tmpWrapper.style.width = ((max-min)+1)*30+"px";
    tmpWrapper.style.width = "100%";
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
