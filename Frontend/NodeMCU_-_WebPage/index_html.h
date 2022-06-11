String INDEX_HTML  = R"=====(
<!DOCTYPE html>
<html>

 <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="style.css" />
    <meta http-equiv="refresh" content="5" />
    <title>Gerenciador de Residuos</title>

    <style>
        * {
          margin: 0;
          padding: 0;
          list-style: none;
        }
        
        body {
          position: relative;
        }
        
        main {
          height: 100vh;
          background: url(https://i.postimg.cc/ZnjcPPhv/figg.gif) no-repeat center;
          width: 100%;
          background-size: cover;
        
        }
        
        .container {
          width: 100%;
          padding: 0 15px;
        }
        
        .box-left {
          width: 25%;
          margin: 0 auto;
        }
        
        .box-right {
          width: 60%;
          margin: 0 auto;
          position: relative;
        }
        
        .box-right::before {
          content: "";
          position: absolute;
          top: 50%;
          left: 0;
          transform: translate(-50%, -50%);
          background: #000;
          width: 3px;
          height: 100%;
        }
        
        .row {
          display: flex;
        }
        
        .box-geral {
          height: 265px;
          width: 100%;
          max-width: 500px;
          background-color: #fff;
          border-radius: 30px;
          position: absolute;
          top: 50%;
          left: 50%;
          transform: translate(-50%, -50%);
          display: flex;
          flex-direction: column;
          justify-content: center;
          align-items: center;
        }
        
        .text-center{
          text-align: center;
        }
        
        .ajuste-text span{
          color: #343434;
        }
        
        #app {
          position: absolute;
          top: 50%;
          left: 50%;
          transform: translate(-50%, -50%);
        }
        
        
        .teste-teste {
          display: flex;
          flex-direction: column;
          justify-content: center;
          align-items: center;
        }
        
        .teste-teste img {
          width: 137px;
        }
        
        .img-2 {
          transition: .6s all ease;
          display: none;
        }
        
        .img-1 {
          display: none;
          animation-name: teste;
          animation-duration: 3s;
          animation-timing-function: linear;
          animation-iteration-count: infinite;
          transition: .6s all ease;
        }

        .img-3{
          display: none;
          transition: .6s all ease;
          }
        
        @keyframes teste {
          0% {
            transform: translate(0px, 0px);
            transform: rotate(0deg);
          }
        
          25% {
            transform: translate(25px, 0);
            transform: rotate(10deg);
          }
        
          50% {
            transform: translate(0px, 0px);
            transform: rotate(-10deg);
          }
        
          75% {
            transform: translate(25px, 0);
            transform: rotate(10deg);
          }
        
          100% {
            transform: translate(0px, 0px);
            transform: rotate(-10deg);
          }
        }
        
        /* Titulo */
        
        .box-title h1 {
          font-size: 15px;
          text-align: center;
        }
        
        .box-title {
          text-align: center;
        }
        
        .box-title p {
          margin: 10px 0;
        }
        
        .box-text span {
          font-size: 20px;
        }
        
        .box-text h4 {
          text-transform: uppercase;
          text-align: center;
          padding: 12px 0;
          border: 1px solid #000;
          border-radius: 20px;
          padding: 5px 10px;
          margin: 10px 0;
        }
        
        
        .ajuste-text{
        padding: 0 20px;
        }

    </style>
    
  </head>
  <body>
    <main>
     <div class="box-geral">
        <div class="container">
          <div class="row">
            <div class="box-left">
              <div class="teste-teste">
                <img class="img-1" src="https://i.postimg.cc/qBKwnpVz/Angry-Pet.png" alt="Logo" />
                <img class="img-2" src="https://i.postimg.cc/DyKgPRn5/Happy-Pet.png" alt="Logo" />
                <img class="img-3" src="https://i.postimg.cc/1t544Rvz/Maintenance-Pet.png" alt="Logo" />
                
                
              </div>
            </div>
            <div class="box-right">
              <div class="teste-teste">
                <div class="box-title">
                  <h1>Olá, eu sou um Gerenciador de Residuos inteligente!</h1>
                  <p>Aqui embaixo vai estar alguns dados sobre mim</p>
                </div>
                <div class="ajuste-text text-center">
                  <h4>Estou com aproximadamente <span id="dist">)=====";String INDEX_HTMLmid  = R"=====(</span> de espaço livre</h4>
                </div>
                <div class="box-text ajuste-text">
                  <h4 id="th4">)=====";String INDEX_HTMLfinal  = R"=====(</h4>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </main>
</body>
<script>
      let img1 = document.querySelector(".img-1");
      let img2 = document.querySelector(".img-2");
      let img3 = document.querySelector(".img-3");
      
      let titleh5 = document.getElementById("th5");
      let titleh4 = document.getElementById("th4");
      
      let distSpan = document.getElementById("dist");
      
      
      
      
      let t1 = "Socorrooo, estou ficando cheia";
      let t2 = "To relax, brota";
      let t3 = "Estou em manutenção, aguarde";
      let dist1 = "20%";
      let dist2 = "40% - 80%";
      let dist3 = "(MANUTENÇÃO)"
      
      
      function teste() {
          if (titleh4.innerHTML === t2) { 
               img2.style.display = 'block';  
               img1.style.display = 'none';  
               img1.style.transition = '.6s all ease';       
           
           } else if (titleh4.innerHTML === t1) { 
               img1.style.display = 'block';  
               img2.style.display = 'none';        
           }
           else if (titleh4.innerHTML === t3){
               img3.style.display = 'block';
               img2.style.display = 'none'; 
               img1.style.display = 'none'; 
            }
      }
      
      function teste2() {
          if (titleh4.innerHTML === t1) { 
              distSpan.append(dist1);
           } else if (titleh4.innerHTML === t2){
              distSpan.append(dist2);
           }
           else if (titleh4.innerHTML === t3){
              distSpan.append(dist3);
           }
      }

      teste2();
      teste();

</script>
</html>
)=====";
