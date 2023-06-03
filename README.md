# EcoNutri EDGE - ESR1

A simulação pode ser acessada no [Projeto Tinkercad](https://www.tinkercad.com/things/cOnHbPL0HSP-copy-of-teste-checkpoint2/editel?sharecode=7KcIDXtigldqlVauARKeTTgSLMGuVG_u2WQ833VMUMg).

---

## Alunos

- Deivison Pertel – **RM 550803**
- Eduardo Akira Murata – **RM 98713**
- Guilherme Jacob Soares da Costa – **RM 84581**
- Fabrizio El Ajouri Romano – **RM 550410**
- Wesley Souza de Oliveira – **RM 97874**

---

# ***EcoNutri: Sistema de Armazenamento Inteligente***

- O sistema de armazenamento inteligente EcoNutri foi desenvolvido para monitorar e controlar as condições de armazenamento de carnes, hortaliças, laticínios e produtos congelados. 
- Ele utiliza sensores de umidade e temperatura para garantir que os alimentos sejam armazenados nas condições ideais. Este readme fornecerá informações sobre os componentes do sistema, o seu funcionamento e como utilizá-lo.

---

## ***Componentes Utilizados :***

- Arduino Uno (ou similar)
- Display LCD (16x2 caracteres)
- Sensor de temperatura
- Sensor de umidade
- Potenciômetro
- Motor
- Interruptor

---

## ***Funcionamento***

O sistema EcoNutri monitora constantemente as condições de umidade e temperatura do ambiente de armazenamento. Com base nas configurações definidas, ele controla o motor para ligar ou desligar os umidificadores e refrigeradores, garantindo que as condições de armazenamento sejam adequadas para cada tipo de alimento.



### O sistema funciona da seguinte maneira :

1. O sensor de umidade e temperatura coleta os dados do ambiente de armazenamento.
2. Com base na configuração selecionada (carnes, hortaliças, laticínios ou congelados), o sistema define os valores de umidade e temperatura ideais para esse tipo de alimento.
3. O display LCD exibe as informações sobre o status do sistema e as condições de armazenamento.
4. O sistema compara as leituras dos sensores com os valores ideais definidos.
5. Se a umidade estiver abaixo do valor ideal, o sistema liga os umidificadores e exibe um aviso no display LCD.
6. Se a umidade estiver dentro da faixa ideal, o sistema mantém os umidificadores desligados e exibe a informação no display LCD.
7. Se a umidade estiver acima do valor ideal, o sistema desliga os umidificadores e exibe um aviso no display LCD.
8. O mesmo processo é realizado para o controle da temperatura.
9. O motor é acionado para controlar os umidificadores e refrigeradores conforme necessário.
10. O sistema continua monitorando e controlando as condições de armazenamento enquanto estiver ligado.

---

## ***Utilização***
1. Monte o circuito: Conecte os componentes conforme o esquema de pinagem especificado no código.

2. Carregue o código: Faça o upload do código para o Arduino utilizando a IDE Arduino ou outro ambiente de desenvolvimento compatível.

3. Conecte os sensores: Certifique-se de que os sensores de umidade e temperatura estão corretamente conectados aos pinos especificados no código.

4. Conecte o display LCD: Conecte os pinos do display LCD aos pinos especificados no código.

5. Conecte o motor: Conecte o motor aos pinos especificados no código, garantindo que ele esteja corretamente ligado aos umidificadores e refrigeradores.

6. Alimentação: Certifique-se de fornecer energia ao Arduino e aos componentes conforme necessário.

7. onfiguração do sistema: No código, é possível ajustar os valores de umidade e temperatura para cada tipo de alimento (carnes, hortaliças, laticínios e congelados) de acordo com as recomendações de armazenamento.

8. Inicialização: Ao ligar o sistema, ele será inicializado e exibirá uma sequência de mensagens no display LCD.

9. Monitoramento e controle: O sistema continuamente monitora as condições de umidade e temperatura do ambiente de armazenamento. Com base nas configurações definidas, ele controla o motor para ligar ou desligar os umidificadores e refrigeradores, mantendo as condições de armazenamento adequadas para cada tipo de alimento.

10. Interrupção do sistema: Utilize o interruptor para ligar ou desligar o sistema de armazenamento. Quando o sistema estiver desligado, ele exibirá uma mensagem correspondente no display LCD.


#### *Observação:* 
 - Este código é uma base para o sistema de controle e pode ser adaptado e expandido de acordo com os requisitos do projeto específico.
- Certifique-se de seguir as boas práticas de segurança ao manipular componentes eletrônicos e ao lidar com alimentos.
