// Complete project details: https://randomnerdtutorials.com/esp32-web-server-websocket-sliders/

var gateway = `ws://${window.location.hostname}/ws`;
var websocket;
window.addEventListener('load', onload);

function onload(event) {
    initWebSocket();
}

function getValues(){
    websocket.send("getValues");
}

function initWebSocket() {
    console.log('Trying to open a WebSocket connection…');
    websocket = new WebSocket(gateway);
    websocket.onopen = onOpen;
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}

function onOpen(event) {
    console.log('Connection opened');
    getValues();
}

function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}

function updateSliderPWM(element) {
    var sliderNumber =  element.id.charAt(element.id.length-2)+element.id.charAt(element.id.length-1);
    var sliderValue = document.getElementById(element.id).value;
    document.getElementById("sliderValue"+sliderNumber).innerHTML = sliderValue;
    console.log(sliderValue);
    websocket.send(sliderNumber+"s"+sliderValue.toString());
}

function fn1(element)
{
 var i = element.id.charAt(element.id.length-2)+element.id.charAt(element.id.length-1);
 if (document.getElementById("div" + i) != null) {
  document.getElementById("div" + i).style.display = "none";
  
  i++;
  document.getElementById("div" + i).style.display = "inline";
  websocket.send("button1");
  i--;
 }
}
function fn2(element)
{
 var i = element.id.charAt(element.id.length-2)+element.id.charAt(element.id.length-1)-1;
 if (document.getElementById("div" + i) != null) {
  document.getElementById("div" + i).style.display = "inline";
  websocket.send("button2");
  i++;
  document.getElementById("div" + i).style.display = "none";
  i--;
    }
 }
function onMessage(event) {
    console.log(event.data);
    var myObj = JSON.parse(event.data);
    var keys = Object.keys(myObj);

    for (var i = 0; i < keys.length; i++){
        var key = keys[i];
        document.getElementById(key).innerHTML = myObj[key];
        document.getElementById("slider"+ (i+11).toString()).value = myObj[key];
    }
}