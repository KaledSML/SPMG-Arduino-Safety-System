# SPMG: Sistema de Prevención de Morición por Gas 🛡️

**SPMG** es un proyecto de seguridad doméstica desarrollado en **Arduino** para combatir la "amenaza silenciosa" del monóxido de carbono (CO) y prevenir incendios. El sistema monitorea el ambiente en tiempo real y emite alertas escalables según el nivel de riesgo detectado.

---

## 📋 Contexto y Justificación
El monóxido de carbono es un gas incoloro, inodoro y altamente tóxico que representa un grave problema de salud pública, especialmente durante el invierno. En muchas regiones, afecta hasta al **30% de la población**, siendo los adultos mayores y niños los más vulnerables. 

Este proyecto nace con el objetivo de proporcionar una solución tecnológica accesible que detecte niveles peligrosos de gas y temperaturas críticas antes de que ocurra un accidente fatal.

## 📺 Demostración y Simulación
Puedes explorar el proyecto y ver la exposición detallada a través de los siguientes enlaces:

*   **Simulación Interactiva:** [Probar circuito en Tinkercad](https://www.tinkercad.com/things/k7bioKIEf07-spmg) 🚀
*   **Video de Presentación:** [Ver exposición en YouTube](https://youtu.be/eweGFmQ_UTY) 📺

---

## 🛠️ Documentación Técnica

### 1. Arquitectura de Hardware (Tinkercad)
El sistema utiliza una placa **Arduino UNO** como núcleo de procesamiento, integrando:
*   **Sensor de Gas (Analógico):** Monitoreo de concentraciones de CO/Humo (Pin A3).
*   **Sensor de Temperatura (TMP36):** Captura de datos térmicos constantes (Pin A0).
*   **Interfaz Visual:** Pantalla LCD 16x2 y sistema de semáforo LED.
*   **Interfaz Sonora:** Buzzer piezoeléctrico para alertas de estado crítico (Pin 13).

### 2. Lógica de Control y Alertas
El software clasifica el riesgo ambiental en tres niveles según la lectura de los sensores:

| Estado | Rango Sensor | Indicador LED | Pantalla LCD | Alerta Sonora |
| :--- | :--- | :--- | :--- | :--- |
| **Normal** | Bajo | Verde | "NORMAL" | Desactivada |
| **Intermedio** | Medio | Amarillo | "INTERMEDIO" | Desactivada |
| **Crítico** | Alto | Rojo | "CRITICO" | **Buzzer Activo** |

### 3. Seguridad Térmica
Se ha programado un umbral de seguridad de **40°C**. Al superar esta temperatura, el sistema activa inmediatamente el modo crítico (LED Rojo + Buzzer) para alertar sobre posibles focos de incendio.

---
*Proyecto universitario diseñado para validar soluciones de ingeniería orientadas a la seguridad y el impacto social.*
