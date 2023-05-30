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

# Controle de Umidade, Temperatura e Luminosidade para Armazenamento de Alimentos Perecíveis
Este é um código para um sistema de controle que monitora e exibe a umidade, temperatura e luminosidade ideais para o armazenamento de alimentos perecíveis. O sistema utiliza sensores para coletar informações dos ambientes e aciona LEDs indicadores e um display LCD para fornecer feedback visual sobre as condições de armazenamento.

---

## Componentes Utilizados
- Arduino
- Display LCD (compatível com a biblioteca LiquidCrystal)
- LEDs vermelho, amarelo e verde
- Sensor de umidade (fotorresistor)
- Sensor de temperatura
- Sensor de luminosidade
- Potenciômetro

---

## Funcionamento
O sistema é composto pelas seguintes etapas:

1. Configuração inicial: Definição dos pinos utilizados, inicialização do display LCD e configuração dos pinos como entradas ou saídas.

2. Loop principal: O código entra em um loop infinito, onde são coletadas as leituras dos sensores e realizado o processamento dos valores.

3. Leitura dos sensores: Os valores dos sensores de temperatura, luminosidade e potenciômetro são lidos e convertidos para as unidades adequadas.

4. Controle de Luminosidade:

- O valor lido do fotorresistor é verificado para determinar o nível de luminosidade.
- Com base no valor lido, os LEDs indicadores são acionados e uma mensagem correspondente é exibida no display LCD.

5. Controle de Umidade:

- O valor lido do sensor de luminosidade é verificado para determinar o nível de umidade.
- Com base no valor lido, os LEDs indicadores são acionados e uma mensagem correspondente é exibida no display LCD.

6. Controle de Temperatura:

- O valor lido do sensor de temperatura é verificado para determinar a temperatura atual.
- Com base no valor lido, os LEDs indicadores são acionados e uma mensagem correspondente é exibida no display LCD.

7. Delay e limpeza do display: Após cada ciclo de verificação, um atraso é introduzido para evitar leituras repetidas muito rápidas. Em seguida, o display LCD é limpo para a próxima atualização.

---

## Utilização

1. Conecte os componentes ao Arduino de acordo com o esquema de circuito adequado.

2. Carregue o código para o Arduino usando o ambiente de desenvolvimento Arduino IDE.

3. Observe as indicações dos LEDs e as mensagens exibidas no display LCD para verificar as condições de umidade, temperatura e luminosidade.

4. Ajuste o potenciômetro para controlar a luminosidade desejada.

5. Personalize as faixas de valores para determinar as condições ideais de acordo com as necessidades específicas de armazenamento dos alimentos perecíveis.

### Observação: 
Este código é uma base para o sistema de controle e pode ser adaptado e expandido de acordo com os requisitos do projeto específico.
