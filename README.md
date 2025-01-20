# Microcontroladores-GPIO-ATIVIDADE-2

# Controle de LEDs e Buzzer no Raspberry Pi Pico

Este projeto demonstra como controlar LEDs e um buzzer conectados a um Raspberry Pi Pico utilizando comandos recebidos via comunicação serial USB.

---

## **Descrição do Projeto**

O código permite controlar três LEDs (vermelho, verde e azul) e emitir um som com um buzzer por meio de comandos enviados via USB. Cada comando realiza uma ação específica nos LEDs ou no buzzer, facilitando testes e interação com os dispositivos.

---

## **Componentes Necessários**

- Raspberry Pi Pico
- 3 LEDs (vermelho, verde e azul)
- 3 resistores (330Ω ou outro valor adequado para LEDs)
- 1 buzzer ativo
- Cabos jumpers
- Protoboard (opcional)

---

## **Conexões de Hardware**

### **LEDs:**

- LED vermelho: GPIO 13 (Pino 17)
- LED verde: GPIO 11 (Pino 15)
- LED azul: GPIO 12 (Pino 16)
- Conecte os catodos (“-”) dos LEDs ao GND através de resistores.

### **Buzzer:**

- Pino positivo do buzzer: GPIO 21 (Pino 27)
- Pino negativo do buzzer: GND

---

## **Comandos Disponíveis**

| Comando | Ação                           |
| ------- | ------------------------------ |
| `r`     | Liga o LED vermelho            |
| `g`     | Liga o LED verde               |
| `b`     | Liga o LED azul                |
| `0`     | Desliga todos os LEDs          |
| `s`     | Emite som no buzzer por 500 ms |

---

## **Como Usar**

1. **Configure o hardware:**

   - Realize as conexões conforme descrito na seção anterior.

2. **Configure o ambiente de desenvolvimento:**

   - Instale o SDK do Raspberry Pi Pico.
   - Configure a IDE (como VS Code ou Thonny).

3. **Compile e carregue o código:**

   - Compile o código em C/C++.
   - Carregue o arquivo binário no Raspberry Pi Pico.

4. **Interaja com o dispositivo:**
   - Utilize uma ferramenta de terminal serial (como PuTTY ou o terminal da IDE).
   - Envie os comandos especificados para controlar os LEDs e o buzzer.

---

## **Expansões Futuras**

- Adicionar mais dispositivos, como sensores ou botões.
- Implementar diferentes frequências para o buzzer.
- Permitir o envio de comandos mais complexos, como sequências de LEDs.

---

## **Licença**

Este projeto é livre para uso educacional e pessoal. Sinta-se à vontade para modificar e expandir conforme necessário.
