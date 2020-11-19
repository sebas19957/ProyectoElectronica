$(document).ready(function () {
    document.getElementById('Content_animate').style.setProperty('--animate-duration', '3s');

    $(document).on('click','.btn', function(){
        var usuario = document.getElementById('usuario').value;
        var password = document.getElementById('password').value;
        if (usuario === 'sebas' && password === 'e123') {
             $('#Content_animateDown').toggle("slow");
             $('#divContentButtons').show(1500);
        } else if(usuario === '' || password === ''){
            $.toast({
                heading: 'Error',
                text: 'Hay espacios en blanco',
                position: 'top-right',
                icon: 'error'
            });
        }else{
            $.toast({
                heading: 'Error',
                text: 'Usuario o contraseña incorrecos',
                position: 'top-right',
                icon: 'error'
            });
        }
        
    });

    $(document).on('click','#pulseVerde', function(){ 
        let verde = document.getElementById('pulseVerde');
        var p1 = 22;
        var p2 = 24;
        var p3 = 26;
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";
            
            $.get("http://192.168.1.65/17/on");
            $.get("http://192.168.1.65/16/on");
            $.get("http://192.168.1.65/4/on");
        } else {
            verde.innerText = "Encender";
            $.get("http://192.168.1.65/17/off");
            $.get("http://192.168.1.65/16/off");
            $.get("http://192.168.1.65/4/off");
        }
    });

    $(document).on('click','#pulseRojo', function(){ 
        let verde = document.getElementById('pulseRojo');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";

            $.get("http://192.168.1.65/23/on");
            $.get("http://192.168.1.65/18/on");
            $.get("http://192.168.1.65/5/on");
        } else {
            verde.innerText = "Encender";

            $.get("http://192.168.1.65/23/off");
            $.get("http://192.168.1.65/18/off");
            $.get("http://192.168.1.65/5/off");
        }
    });

    $(document).on('click','#pulseAzul', function(){ 
        let verde = document.getElementById('pulseAzul');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";

            $.get("http://192.168.1.65/22/on");
            $.get("http://192.168.1.65/21/on");
            $.get("http://192.168.1.65/19/on");
        } else {
            verde.innerText = "Encender";

            $.get("http://192.168.1.65/22/off");
            $.get("http://192.168.1.65/21/off");
            $.get("http://192.168.1.65/19/off");
        }
    });

    $(document).on('click','#pulseAmarillo', function(){ 
        let verde = document.getElementById('pulseAmarillo');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";

            $.get("http://192.168.1.65/0/on");
            $.get("http://192.168.1.65/2/on");
            $.get("http://192.168.1.65/15/on");
        } else {
            verde.innerText = "Encender";

            $.get("http://192.168.1.65/0/off");
            $.get("http://192.168.1.65/2/off");
            $.get("http://192.168.1.65/15/off");
        }
    });

    $(document).on('click','#pulseRGB', function(){ 
        let verde = document.getElementById('pulseRGB');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";

            // RGB1
            $.get("http://192.168.1.65/33/on");
            $.get("http://192.168.1.65/26/on");
            $.get("http://192.168.1.65/27/on");

            // RGB2
            $.get("http://192.168.1.65/32/on");
            $.get("http://192.168.1.65/25/on");
            $.get("http://192.168.1.65/14/on");
            
            // RGB3
            $.get("http://192.168.1.65/12/on");
            $.get("http://192.168.1.65/13/on");
            $.get("http://192.168.1.65/3/on");
        } else {
            verde.innerText = "Encender";

            // RGB1
            $.get("http://192.168.1.65/33/off");
            $.get("http://192.168.1.65/26/off");
            $.get("http://192.168.1.65/27/off");

            // RGB2
            $.get("http://192.168.1.65/32/off");
            $.get("http://192.168.1.65/25/off");
            $.get("http://192.168.1.65/14/off");
            
            // RGB3
            $.get("http://192.168.1.65/12/off");
            $.get("http://192.168.1.65/13/off");
            $.get("http://192.168.1.65/3/off");
        }
    });

    $(document).on('click','#pulseSRGB', function(){ 

        let verde = document.getElementById('pulseSRGB');
        if (verde.innerText === "Encender") {
            verde.innerText = "Apagar";

             // RGB1
             $.get("http://192.168.1.65/33s/on");
             $.get("http://192.168.1.65/26s/on");
             $.get("http://192.168.1.65/27s/on");
 
             // RGB2
             $.get("http://192.168.1.65/32s/on");
             $.get("http://192.168.1.65/25s/on");
             $.get("http://192.168.1.65/14s/on");
             
             // RGB3
             $.get("http://192.168.1.65/12s/on");
             $.get("http://192.168.1.65/13s/on");
             $.get("http://192.168.1.65/3s/on");

             $.toast({
                text: 'La secuencia dura 8 segundos',
                position: 'top-right',
                icon: 'info',
            })

             setInterval(cambiar, 8000);  
        } 
    });

    function cambiar (){
        let verde = document.getElementById('pulseSRGB');
        if (verde.innerText === "Apagar") {
            verde.innerText = "Encender"
            console.log('Se apago de nuevo');

            $.get("http://192.168.1.65/33s/off");
            $.get("http://192.168.1.65/26s/off");
            $.get("http://192.168.1.65/27s/off");

            // RGB2
            $.get("http://192.168.1.65/32s/off");
            $.get("http://192.168.1.65/25s/off");
            $.get("http://192.168.1.65/14/off");
            
            // RGB3
            $.get("http://192.168.1.65/12s/off");
            $.get("http://192.168.1.65/13s/off");
            $.get("http://192.168.1.65/3s/off");
        }
    }
});