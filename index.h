const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
  <title>AVE RnD : CW Keyer Ver 1.1</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  
  
    <style>
.button {
  background-color: #4CAF50; /* Green */
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 20px;
  margin: 4px 2px;
  cursor: pointer;
}

.button2 {background-color: #008CBA;} /* Blue */
.button3 {background-color: #f44336;} /* Red */ 
.button4 {background-color: #e7e7e7; color: black;} /* Gray */ 
.button5 {background-color: #555555;} /* Black */
</style>
  
  
  
  
  
  <style> 
  
  
  body {
  background-color: lightgreen;
  color: black;
}
  
  
.input.one[type=text] {
  width: 100%;
  padding: 12px 20px;
  margin: 8px 0;
  box-sizing: border-box;
  border: 3px solid #ccc;
  -webkit-transition: 0.5s;
  transition: 1.5s;
  outline: none;
  font-size:30px;
  font-family: monospace;
  
   border: 4px solid blue;
  border-radius: 7px;
}

.input.one[type=text]:focus {
  border: 3px solid #555;
}


.input.two[type=text] {
  width: 70%;
  padding: 12px 20px;
  margin: 8px 0;
  box-sizing: border-box;
  border: 3px solid #ccc;
  -webkit-transition: 0.5s;
  transition: 1.5s;
  outline: none;
  font-size:22px;
  font-family: monospace;
  
   border: 4px solid orange;
  border-radius: 7px;
}

.input.two[type=text]:focus {
  border: 3px solid #555;
}



</style>
  





<style>
.slidecontainer {
  width: 100%;
}

.slider {
  -webkit-appearance: none;
  width: 100%;
  height: 25px;
  background: #d3d3d3;
  outline: none;
  opacity: 0.7;
  -webkit-transition: .2s;
  transition: opacity .2s;
}

.slider:hover {
  opacity: 1;
}

.slider::-webkit-slider-thumb {
  -webkit-appearance: none;
  appearance: none;
  width: 25px;
  height: 25px;
  background: #04AA6D;
  cursor: pointer;
}

.slider::-moz-range-thumb {
  width: 25px;
  height: 25px;
  background: #04AA6D;
  cursor: pointer;
}
</style>




<style>

fieldset {
  background-color: #eeeeee;
}

legend {
  background-color: gray;
  color: white;
  padding: 5px 10px;
}
</style>


  
  
  </head>
<body>

 <div>
  <center>
<input class="input one" type=text id="sendreceipt" disabled>
<p></p>   
 <input class="input one" type=text id="txtcw" >
<p></p>  
</center>
</div>
  
  
  <script>

 
    
    var newCount=0;
    var oldCount=0; 
   
    var newArray;
    var newArrayLength=0;
    var oldArray;
    var oldArrayLength=0;
var count=0;
    var status;
    var cw=" ";


    
    
    

    
       
    
    
    setInterval(function() {
  // Call a function repetatively with .5 Second interval
  
 
  

if(document.getElementById("txtcw").value == ""){
 //  cw=" "; // reset previous send messages
  document.getElementById("txtcw").value=" ";
document.getElementById('txtcw').focus();
  }

  
  
 newArray = Array.from(document.getElementById("txtcw").value);
 newArrayLength = newArray.length;
 
 

   if(oldArrayLength >= newArrayLength ){
    // count = txtArrayLength
    status = "less";

  
    
   count = count - (oldArrayLength - newArrayLength);
    
     }
     
     
     if(oldArrayLength == newArrayLength ){
    // count = txtArrayLength
    status = "same";
     
     }
     
     
       if(oldArrayLength < newArrayLength ){
    // count = txtArrayLength
    status = "more";
     
     }
     

      
    
    // console.log(txtArray)
    console.log("New Array Length: " + newArray )
       console.log("Old Array Length: " + oldArray )
       

    oldArray=newArray;// storing previous array
    oldArrayLength = newArrayLength;//  storing previous length data
    
    
    
 //   if(newArrayLength >= 0){ 

          if( count <= newArrayLength){  //////// = edited
                cw += newArray[count]; // for monitor display
          // Sending data string
         // sendData(cw);
        //sendData(document.getElementById("txtcw").value);

       
         
            count++;
                            }else{ count = count-1;  }



 sendData(document.getElementById("txtcw").value);
 
 //  document.getElementById("showcount").value = count;                       
                                 
          
   //  }
    




      
}, 700); //700mSeconds update rate


  </script>
  
  <div id="demo">
  <button class="button button3" type="button" onclick="ClearScreen()">Clear Screen</button>
  <br>
</div>






 <div>
<input class="input two" type=text id="edit_txt_1">
<button class="button button1" type="button" onclick="edit_1()"> Go >> </button>
<p></p>   
</div>
<script>
function edit_1(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_1").value;
  document.getElementById("txtcw").focus();
}
</script>




 <div>
<input class="input two" type=text id="edit_txt_2">
<button class="button button1" type="button" onclick="edit_2()"> Go >> </button>
<p></p>   
</div>
<script>
function edit_2(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_2").value;
  document.getElementById("txtcw").focus();
}
</script>


 <div>
<input class="input two" type=text id="edit_txt_3">
<button class="button button1" type="button" onclick="edit_3()"> Go >> </button>
<p></p>   
</div>
<script>
function edit_3(){
  document.getElementById("txtcw").value = document.getElementById("txtcw").value + " " + document.getElementById("edit_txt_3").value;
  document.getElementById("txtcw").focus();
}
</script>




<div class="slidecontainer">
 <fieldset>
  <legend>Set WPM</legend>
  <input onchange="change_wpm()" oninput="show_sweeped_wpm()" id="speed" type="range" min="40" max="150" value="90" class="slider" >
  Change/Set New DIT time : <b><i id="ditime">???</i></b> Milli Second
  <br>
  Saved DIT time : <b><i id="receiptwpm"></i></b> Milli Second
 </fieldset>
 <p></p>
 <p></p>
</div>

<div class="slidecontainer">
 <fieldset>
  <legend>Set Side Tone frequency</legend>
  <input onchange="change_tone()" oninput="show_sweeped_tone()" id="sidetone" type="range" min="50" max="2000" value="500" class="slider" >
  Change/Set New Side Tone frequecy : <b><i id="side_tone">???</i></b> Hertz
  <br>
  Saved Side Tone frequency : <b><i id="receipttone"></i></b> Hertz
 </fieldset>
</div>

<script>
  
function show_sweeped_wpm(){
  // only diplay :  instantanious selected values of sweep selector
document.getElementById("ditime").innerHTML = document.getElementById("speed").value; 
  
} 

function show_sweeped_tone(){
  // only diplay :  instantanious selected values of frequency selector
document.getElementById("side_tone").innerHTML = document.getElementById("sidetone").value; 
  
} 


  
    
function change_wpm(){
  //up on final select from sweep bar..send and set new wpm in eeprom
document.getElementById("ditime").innerHTML = document.getElementById("speed").value;
document.getElementById('txtcw').focus();
// sending milliseconds value
sendWpm(document.getElementById("speed").value);

}

function change_tone(){
  //up on final select from sweep bar..send and set new wpm in eeprom
document.getElementById("side_tone").innerHTML = document.getElementById("sidetone").value;
document.getElementById('txtcw').focus();
// sending frequency value
 sendTone(document.getElementById("sidetone").value);

}

</script>






<script>
function ClearScreen(){
document.getElementById('txtcw').value=" ";
document.getElementById('txtcw').focus();
}
</script>






<script>
// ALL FUNCTIONS TO SEND DATA OVER AJAX

function sendData(txt) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("sendreceipt").value =
      this.responseText;
    }
  };
  xhttp.open("GET", "cwtxt?mytxt="+txt, true);
  xhttp.send();
}
 


function sendWpm(txt) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("receiptwpm").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "wpmtxt?mytxt="+txt, true);
  xhttp.send();
}


function sendTone(txt) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("receipttone").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "tonetxt?mytxt="+txt, true);
  xhttp.send();
}




</script>


 
 <script>
 const myTimeout = setTimeout(getSavedWpm, 5000);

// Exicuite the below function after the TIMESET = 5 Seconds // for retriving Saved WPM milliseconds for display purpose
 
 function getSavedWpm(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("receiptwpm").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "wpmback?mytxt=1", true);
  xhttp.send();  
 }
 
 </script>


  <script>
 const myTimeout1 = setTimeout(getSavedTone, 7000);

// Exicuite the below function after the TIMESET = 7 Seconds // for retriving Saved Side tone frequency (Heartz)for display purpose
 
 function getSavedTone(){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("receipttone").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "toneback?mytxt=1", true);
  xhttp.send();  
 }
 
 </script>
<div>
for comments : <b>vu3ave</b>@gmail.com
</div>
  </body>
</html>
)=====";
