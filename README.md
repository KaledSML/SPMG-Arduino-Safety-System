# 🛡️ SPMG: Sistema de Prevención de Monóxido y Gas

<p align="center">
  <img src="https://img.shields.io/badge/SKILLS-C++%20/%20ARDUINO-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
  <img src="https://img.shields.io/badge/SKILLS-ELECTRONICA-FFD700?style=for-the-badge&logo=circuitverse&logoColor=black" />
  <img src="https://img.shields.io/badge/SKILLS-SISTEMAS%20DE%20CONTROL-E91E63?style=for-the-badge" />
  <img src="https://img.shields.io/badge/SKILLS-DOCUMENTACIÓN%20TÉCNICA-4CAF50?style=for-the-badge" />
</p>

---

## 📝 Descripción del Proyecto
El **Sistema de Prevención de Monóxido y Gas (SPMG)** es una solución de hardware embebido diseñada para detectar la "muerte silenciosa" por monóxido de carbono. El sistema realiza un monitoreo ambiental constante y activa protocolos de emergencia ante niveles críticos de gas o temperatura.

> **Nota de Transparencia:** Este repositorio conserva el código original de mi etapa de formación inicial. Se mantiene sin modificaciones para documentar mi progresión técnica y mis fundamentos en lógica de programación.

---

## 📺 Evidencia Técnica y Simulación

<p align="center">
  <a href="https://www.tinkercad.com/things/k7bioKIEf07-spmg">
    <img src="https://img.shields.io/badge/PROBAR_CIRCUITO-Tinkercad-FF6A00?style=for-the-badge&logo=autodesk&logoColor=white" alt="Tinkercad" />
  </a>
  &nbsp;&nbsp;
  <a href="https://youtu.be/eweGFmQ_UTY">
    <img src="https://img.shields.io/badge/PRESENTACIÓN_TÉCNICA-YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white" alt="YouTube" />
  </a>
</p>

---

## 📊 Arquitectura de Lógica (Mermaid)

```mermaid
graph TD
    Start((Inicio)) --> Sense[Lectura Sensores A0 & A3]
    Sense --> Logic{Procesamiento}
    
    Logic -->|Map 0-2| Gas[Nivel de Gas]
    Logic -->|ADC Conv| Temp[Grados Celsius]
    
    Gas -->|Caso 0| G1[Estado: Normal]
    Gas -->|Caso 1| G2[Estado: Alerta]
    Gas -->|Caso 2| G3[Estado: Crítico]
    
    Temp -->| > 40°C | G3
    Temp -->| < 40°C | T1[Estado: Seguro]

    G1 & G2 & G3 & T1 --> Display[Salida LCD 16x2]
    G3 --> Alarm[Activación Buzzer + LED Rojo]
    Display --> Loop[Retorno al Inicio]
    
    style G3 fill:#ff0000,stroke:#333,stroke-width:2px,color:#fff
    style G1 fill:#00ff00,stroke:#333,stroke-width:2px,color:#000
```
---
## 🛠️ Especificaciones Técnicas

### 1. Hardware y Periféricos
| Componente | Función Técnica | Pin / Conexión |
| :--- | :--- | :--- |
| **Arduino UNO** | Microcontrolador central (ATmega328P) | Cerebro del sistema |
| **Sensor MQ (Gas)** | Detección analógica de partículas | Entrada Analógica A3 |
| **TMP36 (Temp)** | Medición de temperatura ambiente | Entrada Analógica A0 |
| **LCD 16x2** | Interfaz visual de usuario (HMI) | Pines 12, 11, 5, 4, 3, 2 |
| **Buzzer Activo** | Alerta auditiva de alta frecuencia | Pin Digital 13 |
| **LEDs (R/A/V)** | Indicadores visuales de estado (Semáforo) | Pines 6, 7, 8 |

### 2. Segmentación de Riesgos (Lógica de Control)
| Rango (Map) | Estado | Acción de Hardware | Mensaje LCD |
| :---: | :--- | :--- | :--- |
| **0** | **Normal** | LED Verde Encendido | "NORMAL" |
| **1** | **Intermedio** | LED Amarillo Encendido | "INTERMEDIO" |
| **2** | **Crítico** | LED Rojo + Buzzer (ON) | "CRITICO" |

---

## 🧪 Algoritmo Principal
Para la gestión de temperatura, el firmware implementa la siguiente conversión ADC a Celsius:

$$T = -40 + 0.488155 \times (LecturaADC - 20)$$

Para la normalización de las lecturas del sensor de gas, se aplica una función de mapeo lineal:
```cpp
int rango = map(sensor, 85, 382, 0, 3);
```
---

## 📈 Impacto Social e Innovación
A diferencia de los sensores industriales costosos, **SPMG** se posiciona como una alternativa de **bajo costo y código abierto**, permitiendo que comunidades en situaciones de vulnerabilidad energética puedan acceder a un sistema de alerta temprana. 

En regiones con climas extremos, donde el uso de calefacción a combustión es una necesidad vital, este proyecto demuestra que la ingeniería puede (y debe) ser una herramienta de prevención directa para salvar vidas.

---

> **"La ingeniería no solo resuelve problemas, protege lo que más importa."** ✨

