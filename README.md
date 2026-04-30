# STM32 ADC & PWM - Register Programming

## Überblick
Dieses Projekt demonstriert die Low-Level Register-Programmierung des STM32F401RE für:
- **ADC** (Analog-Digital-Converter) mit Potentiometer
- **PWM** (Pulse Width Modulation) zur LED Helligkeitssteuerung

**Keine Libraries, keine HAL – reine CMSIS Register-Programmierung!**

## Hardware Setup
| Komponente | Pin | Funktion |
|------------|-----|----------|
| Potentiometer | A4 (PC1) | ADC Eingang (ADC1_IN11) |
| LED | D7 (PA8) | PWM Ausgang (TIM1_CH1) |
| Widerstand | 220Ω | Strombegrenzung |

## Lerninhalte

### ADC
- Aktivierung ADC1 (APB2 Bus)
- PC1 als analogen Eingang konfigurieren
- Single Conversion Mode mit Software-Start
- 12-Bit Ergebnis auslesen (0-4095)

### PWM
- Timer1 Konfiguration (APB2 Bus)
- PWM Mode 1 auf Kanal 1 (PA8)
- PSC und ARR für Frequenz (1 kHz)
- CCR1 für Duty Cycle (0-100%)
- MOE (Main Output Enable) für TIM1

## Ergebnis
Poti drehen → LED Helligkeit ändert sich stufenlos

## Autor
Franck Morel - Bare-Metal Lernprojekt
