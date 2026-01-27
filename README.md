# 🛡️ SPMG: Sistema de Prevención de Monóxido y Gas

**SPMG** es una solución de hardware embebido basada en **Arduino** diseñada para mitigar la "amenaza silenciosa" del monóxido de carbono (CO) y prevenir incendios domésticos. El sistema realiza un monitoreo ambiental constante, activando protocolos de alerta escalables según el nivel de riesgo detectado.

---

## 📺 Evidencia y Simulación
*   **Simulación Interactiva:** [Probar circuito en Tinkercad](https://www.tinkercad.com/things/k7bioKIEf07-spmg) 🚀
*   **Video de Presentación:** [Ver exposición técnica en YouTube](https://youtu.be/eweGFmQ_UTY) 📺

---

## 🛠️ Especificaciones Técnicas

### 1. Arquitectura de Hardware
El sistema integra múltiples periféricos gestionados por un microcontrolador **Arduino UNO**:
*   **Detección de Gas:** Sensor analógico (Pin A3) con mapeo de rangos dinámicos.
*   **Monitoreo Térmico:** Sensor **TMP36** (Pin A0) con procesamiento de señal para conversión a grados Celsius.
*   **Interfaz de Usuario:** Pantalla **LCD 16x2** (vía librería `LiquidCrystal`) para estados en tiempo real.
*   **Protocolo de Alerta:** Semáforo LED tri-color y Buzzer piezoeléctrico de alta frecuencia (Pin 13).

### 2. Lógica de Programación (Firmware)
El código implementa una estructura de control basada en umbrales de seguridad:
*   **Procesamiento de Señal:** Uso de la función `map()` para segmentar la lectura analógica del sensor de gas en niveles discretos (Normal, Intermedio, Crítico).
*   **Control Térmico:** Algoritmo de conversión analógica a digital (ADC) para temperatura:
    $$T = -40 + 0.488155 \times (LecturaADC - 20)$$
*   **Seguridad Activa:** Al superar los **40°C** o niveles altos de gas, el sistema entra en **Modo de Emergencia**, bloqueando el estado en "Crítico" y activando la alerta sonora continua.

## 📋 Impacto Social
En regiones con climas fríos, los accidentes por monóxido afectan hasta al **30% de la población** debido al mal uso de calefactores. Este proyecto democratiza la seguridad doméstica mediante el uso de **tecnología de bajo costo** y código abierto.

---

## 🔧 Fragmento de Lógica Principal (C++)
```cpp
// Segmentación de rangos de riesgo
int sensor = analogRead(A3); 
int rango = map(sensor, sensor_minimo, sensor_maximo, 0, 3);

switch (rango) {   
  case 0: // Estado Normal
    visualizarEstado("NORMAL", verde); 
    break;
  case 2: // Estado Crítico
    digitalWrite(13, HIGH); // Activación de Buzzer
    visualizarEstado("CRITICO", rojo);
    break;
}
