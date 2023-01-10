# PIC-Projeto_Theremin
## O que é o Projeto?

<p>Projeto que consiste em um instrumento theremin usando um sensor ultrassônico, no qual um auto-falante emite frequências sonoras diferentes em relação a proximidade com o sensor ultrassônico utilizado num raio de 120 cm e controle do volume do alto-falante feito por um potenciômetro.</p>

<p>Por meio da biblioteca Ultrasonic.h é usada a função que por meio dos pinos de trigger e echo conectados ao circuito, é retornado uma distancia em centímetros.Esse distancia é utilizada para calcular uma frequencia por meio da fórmula <b>Frequência = 1500 - (distância * 10)</b>. Esse valor de frequência calculado em seguida, usando a biblioteca toneAC, é passado a frequência a ser aplicada e escutada pelo speaker. O controle de volume é realizado por um potenciômetro conectado ao positivo do speaker.</p>
