# ⏳ Clock e Temporizadores  

Repositório contendo projetos para utilização de **clock e temporizadores** no microcontrolador **Raspberry Pi Pico W** utilizando o **Pico SDK**.  

---

## 📂 Estrutura do Repositório  

📁 **projeto_temporizadores/**  
🔹 Implementação da prática utilizando a função `add_repeating_timer_ms()` para criar um **semáforo com temporização de 3 segundos**.  
🔹 Simulação realizada no **Wokwi**.  

📁 **temporizador_um_disparo/**  
🔹 Implementação da prática utilizando a função `add_alarm_in_ms()` para criar um **temporizador de um disparo (One Shot)** acionado por um botão.  
🔹 Simulação realizada no **Wokwi**.  

---

## 📝 Descrição das Atividades  

### 🟢 Atividade 1: Temporizador Periódico (Semáforo)  
Utilizando a função `add_repeating_timer_ms()`, um semáforo é simulado seguindo a sequência:  

✅ **Vermelho → Amarelo → Verde**, com um intervalo de **3 segundos** entre as trocas de sinal.  
✅ A mudança de estado dos LEDs ocorre na função de callback do temporizador (`repeating_timer_callback()`).   
✅ Simulação no **Wokwi** e experimentação no **BitDogLab** utilizando um **LED RGB** nos GPIOs 11, 12 e 13.  

---

### 🔵 Atividade 2: Temporizador de um Disparo (One Shot)  
Utilizando a função `add_alarm_in_ms()`, um sistema é criado para acionar LEDs ao pressionar um botão.  

✅ **Funcionamento:**  
1️⃣ Ao pressionar o **pushbutton**, os três LEDs acendem.  
2️⃣ A cada **3 segundos**, um LED é apagado até que todos estejam desligados.  
3️⃣ O botão **só pode ser pressionado novamente** quando todos os LEDs forem apagados.  
4️⃣ Implementação opcional de **software debounce** para evitar o efeito bouncing no botão.  
✅ Simulação no **Wokwi** e experimentação no **BitDogLab** utilizando o **LED RGB** nos GPIOs 11, 12 e 13 e o **Botão A** no GPIO 05.  

---

## 🛠 Ferramentas Utilizadas  
- **Raspberry Pi Pico W**  
- **Pico SDK**  
- **C/C++**  
- **Wokwi** (Simulação)
- **BitDogLab** (Testes com LED RGB e botão)  
