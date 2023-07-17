# Sistemas Embarcados - Contato Inicial

Utilize o kit com Arduino entregue a você para implementar dois programas com as seguintes especificações. A documentação e o código fonte de cada solução devem estar em diretórios separados.


## Programa 1 - Interruptor LED

1. Monte um circuito com um Arduino, um LED e um botão, conforme desenvolvido nas aulas.

2. Desenhe a máquina de estados e implemente o software de uma aplicação que utilize o botão para acender e apagar o LED. O botão funciona como interruptor, ou seja, cada vez que o botão for pressionado, o estado do LED se alterna entre ligado e desligado. Considere uma solução sem repique (debounce).

3. O código-fonte e a documentação do seu trabalho deve estar no GitHub. A documentação deve estar no arquivo README.md do diretório da aplicação, e deve incluir o esquema elétrico utilizado e o(s) diagrama(s) de máquina(s) de estado.

Dica 1: esta solução foi feita em aula. Reaproveite as informações/código desenvolvidos com o professor e organize sua entrega.

<p align="center">Resolução programa 1</p>

- [Resolução Interruptor LED](interruptor-led) - Interruptor LED

## Programa 2 - Voltímetro Digital

Documente a solução e implemente um voltímetro digital, conforme debatido em sala de aula. O sistema embarcado desenvolvido deve ter as seguintes propriedades:

* Entradas: scale (botão), hold (botão), sinal de tensão (potenciômetro), timer/delay
* Saída: Serial (para saída do valor de tensão medido)
* A saída serial deve atualizar o valor de tensão medido no potenciômetro a cada 500ms.
* O botão scale deve alternar, cada vez que é pressionado, a resolução do valor de tensão entre V (volts) e mV (milivolts). O comportamento deste botão é similar ao "interruptor" do programa 1.
* O botão hold deve suspender a atualização da saída, ou seja, se o botão estiver pressionado, o voltímetro para de atualizar a saída serial. Se não estiver pressionado, a saída é atualizada normalmente.

<p align="center">Resolução programa 2</p>

- [Resolução Voltímetro Digital](voltimetro-digital) - Voltímetro Digital

## Autor

<a href="https://github.com/jeffersonbcr">
    <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/58866006?v=4" width="100px;" alt=""/><br />
    <sub><b>Jefferson Botitano</b></sub></a>
