-------------------------------------
'use strict';
var vcanvas, ctx;

function init() {
    vcanvas = document.getElementById("myCanvas");
    ctx = vcanvas.getContext("2d");
}

function set_key(event) {        ππ
    if(event.keyCode) {            // λ§μ½ event.keyCodeκ° λ€μ΄μ€λ©΄ ifλ¬Έ μ€ν
        ctx.font = "30px Georgia";
        ctx.fillText("keyCode : " + event.keyCode, 200, 200);
    }
}   

function stop_key(event) {
    ctx.clearRect(0, 0, vcanvas.width, vcanvas.height);
}

document.onkeydown = set_key;  // λ¬Όλ¦¬ν€λ₯Ό λλ μ λ set_key() ν¨μ λ°μ 
document.onkeyup = stop_key;   // λ¬Όλ¦¬ν€λ₯Ό λμ λ stop_key() ν¨μ λ°μ
-------------------------------------

/* ν€λ³΄λ μ΄λ²€νΈ νμ
    onkeydown : ν€λ₯Ό λλ μ λ λ°μ, λ¬Όλ¦¬ν€μ λ°μ, νμ¬ λλ¦° λ¬Έμμλ μκ΄μμ΄ λ¬Όλ¦¬ ν€μλ§ λ°μ

    onkeyup : ν€λ₯Ό λΌμμ λ λ°μ
    
*/ 
              β document κ°μ²΄ : document κ°μ²΄λ μΉ νμ΄μ§ κ·Έ μμ²΄λ₯Ό μλ―Ένλ€.
                                  μΉ νμ΄μ§μ μ‘΄μ¬νλ HTML μμμ μ κ·Όνκ³ μ ν  λλ λ°λμ Document κ°μ²΄λΆν° μμν΄μΌ νλ€.
                                  
                
               β³οΈ Q. set_keyμ stop_key ν¨μμμ λ§€κ°λ³μ eventλ λλμ²΄ λ¬΄μμΌκΉ?

                   A. μ΄λ²€νΈ μ€νμ, μ΄λ²€νΈμ λ±λ‘λ ν¨μκ° μ€νλλ€.
                      μ΄λ μ΄ ν¨μμ event κ°κ° λ§€κ°λ³μλ‘ μ£Όμ΄μ§λ€λ λ»μ΄λ€.
                      μ¬μ©μλ μ½λμμ μ΄λ₯Ό λ°μλλκ³  λ°μ§ μμλ λ©λλ€. 
                      
                      λ§€κ°λ³μ μ΄λ―λ‘ κΌ­ λ³μλͺμ 'event'λ‘ μ¬μ©ν  νμλ μμ§λ§ λ³΄ν΅ μ΄λ²€νΈ κ°μ²΄μ μλ―Έλ‘ 'event'λ 'e'λ‘ λ§μ΄ μ¬μ©νλ€.

                    bt.onclick = function(event) {  // μ΄λ° μμΌλ‘..
                      event.μμ±
                      event.λ©μλ
                    }
                             


--------------------------
'use strict';
var vcanvas, ctx;
var x, y;
var vel = 8;

function drawShip(sx, sy) {  // λΉνμ  ν¨μ
    ctx.beginPath();
    ctx.moveTo(sx - 15, sy);
    ctx.lineTo(sx, sy - 15);
    ctx.lineTo(sx + 60, sy);
    ctx.lineTo(sx, sy + 15);
    ctx.closePath();
    ctx.fillStyle="red";
    ctx.fill();

    ctx.beginPath();
    ctx.moveTo(sx + 60, sy);
    ctx.lineTo(sx + 40, sy - 4);
    ctx.lineTo(sx + 40, sy + 4);
    ctx.closePath();
    ctx.fillStyle = "yellow";
    ctx.fill();

    ctx.beginPath();
    ctx.moveTo(sx - 30, sy - 8);
    ctx.lineTo(sx - 10, sy - 8);
    ctx.lineTo(sx - 10, sy - 13);
    ctx.lineTo(sx - 15, sy - 13);
    ctx.closePath();
    ctx.fillStyle = "blue";
    ctx.fill();

    ctx.beginPath();
    ctx.moveTo(sx - 30, sy + 8);
    ctx.lineTo(sx - 10, sy + 8);
    ctx.lineTo(sx - 10, sy + 13);
    ctx.lineTo(sx - 15, sy + 13);
    ctx.closePath();
    ctx.fill();

    ctx.beginPath();
    ctx.arc(sx + 10, sy, 5, 0, Math.PI * 2);
    ctx.fillStyle = "skyblue";
    ctx.fill();
}

function init() {
    vcanvas = document.getElementById("myCanvas");
    ctx = vcanvas.getContext("2d");

    x = 200;
    y = 200;

    drawShip(x, y);
}

function μμ§μ΄κΈ°(event) {                   
    if(event.keyCode === 37) { x -= vel; }  // Left
    if(event.keyCode === 38) { y -= vel; }  // UP
    if(event.keyCode === 39) { x += vel; }  // Right
    if(event.keyCode === 40) { y += vel; }  // Down

    drawShip(x, y);
}

function κ°λ§ν(event) {
    
}

document.onkeydown = μμ§μ΄κΈ°;
document.onkeyup = κ°λ§ν;
--------------------------------
