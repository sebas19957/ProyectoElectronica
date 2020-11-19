$(document).ready(function () {

    $(document).on('click','#pulseVerde', function(){ 
        let verde = document.getElementById('pulseVerde');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";
        } else {
            verde.innerText = "Encender";
        }
    });

    $(document).on('click','#pulseRojo', function(){ 
        let verde = document.getElementById('pulseRojo');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";
        } else {
            verde.innerText = "Encender";
        }
    });

    $(document).on('click','#pulseAzul', function(){ 
        let verde = document.getElementById('pulseAzul');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";
        } else {
            verde.innerText = "Encender";
        }
    });

    $(document).on('click','#pulseBlanco', function(){ 
        let verde = document.getElementById('pulseBlanco');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";
        } else {
            verde.innerText = "Encender";
        }
    });

    $(document).on('click','#pulseRGB', function(){ 
        let verde = document.getElementById('pulseRGB');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";
        } else {
            verde.innerText = "Encender";
        }
    });

    $(document).on('click','#pulseSRGB', function(){ 
        let verde = document.getElementById('pulseSRGB');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";
        } else {
            verde.innerText = "Encender";
        }
    });
    
});