# 🎮 4-in-1 LED Matrix Board

<p align="center">
  <img src="https://img.shields.io/badge/Platform-Arduino_Nano-00979D?style=for-the-badge&logo=arduino" />
  <img src="https://img.shields.io/badge/Display-5x7_LED_Matrix-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/PCB-KiCad-314CB0?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Modes-4_Interactive-purple?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Institute-NSUT-blue?style=for-the-badge" />
</p>

> **Centre for Electronic Design and Technology**  
> Netaji Subhas University of Technology, New Delhi  
> *Date: December 2024*

---

## 📋 Table of Contents
- [Synopsis](#-synopsis)
- [Introduction](#-introduction)
- [System Overview](#-system-overview)
- [Working Modes](#-working-modes)
- [Program Logic](#-program-logic)
- [Inputs & Control](#-inputs--control)
- [Bill of Materials](#-bill-of-materials)

---

## 🎯 Synopsis

A compact and multifunctional **5×7 LED dot matrix system** built around an **Arduino Nano**. It integrates **four interactive modules** into a single educational platform:

- 🔤 **Morse Tutor** — Learn Morse code interactively
- ⏳ **LED Hourglass** — Tilt-controlled sand animation
- 👁️ **Persistence of Vision (POV) Demo** — Visual persistence effect
- 🌡️ **Temperature Display** — Real-time thermistor reading

User interaction is achieved via **buttons**, **tilt switches**, and a **potentiometer**. The system leverages **Timer1 CTC interrupts** for flicker-free LED multiplexing.

## 📖 Introduction

LED matrices are widely used in educational and commercial applications. This project creates a single, compact platform that consolidates multiple mini-projects, enabling learners to explore different aspects of embedded system design:

| Mode | Concept Demonstrated |
|------|---------------------|
| Morse Tutor | Digital output control, timing-based signal generation |
| Hourglass | Tilt-sensor input handling, animation sequencing |
| POV Demo | Persistence-of-vision, real-time potentiometer control |
| Temperature | Analog sensor reading, calculation, text rendering |

## 🔧 System Overview

### Block Diagram
<p align="center">
  <img src="Block Diagram/" alt="Block Diagram" width="600"/>
</p>

### Pin Assignment (Arduino Nano)

| Pin | Signal | Connected To | Function |
|-----|--------|-------------|----------|
| D2-D8 | R1-R7 | ULN2003 | Row drives for LED matrix |
| D9-D13 | C1-C5 | BC327 transistors | Column drives |
| A1-A3 | BTN1-3 | Push Buttons | Navigation (Next/Prev/Select) |
| A4-A5 | Tilt 1-2 | Tilt Switches | Hourglass orientation |
| A6 | Thermistor | NTC | Temperature sensing |
| A7 | Pot | RV1 | POV speed control |

## 🎮 Working Modes

### 1. 🏠 Home Screen
Menu navigation using three push buttons (Next, Previous, Select). Long press (~5s) on Button 1 returns to home from any mode.

### 2. 🔤 Morse Tutor
Displays Morse code patterns for A–Z on the LED matrix with timing-based dot/dash rendering.

### 3. ⏳ Hourglass
Tilt-controlled sand animation with direction detection. Passive buzzer alerts when timer completes.

### 4. 👁️ POV Demo
Potentiometer controls Timer1 compare register, varying refresh frequency to demonstrate persistence-of-vision effect.

### 5. 🌡️ Temperature Display
NTC thermistor with **Beta parameter model** for temperature calculation, displayed as scrolling digits on the matrix.

## ⚙️ Program Logic

The firmware follows a **cooperative architecture**:
- **Foreground (main loop)**: User input processing, mode logic, display buffer updates
- **Background (Timer1 ISR)**: Column-wise LED multiplexing at high speed for flicker-free display

## 📦 Bill of Materials

| S.No | Component | Value | Qty |
|------|-----------|-------|-----|
| 1 | Arduino Nano | — | 1 |
| 2 | 5×7 LED Matrix | — | 1 |
| 3 | ULN2003 | Darlington Array | 1 |
| 4 | BC327 | PNP Transistor | 5 |
| 5 | Push Buttons | — | 3 |
| 6 | Tilt Switches | — | 2 |
| 7 | NTC Thermistor | 10 kΩ | 1 |
| 8 | Potentiometer | — | 1 |
| 9 | Passive Buzzer | — | 1 |

## 🛠️ Technologies Used

`Arduino (C/C++)` · `KiCad` · `Timer Interrupts (CTC)` · `Embedded Systems` · `PCB Design`

## 👥 Author
- **Ansh Gupta** — NSUT, New Delhi

---
*Centre for Electronic Design and Technology, NSUT, New Delhi*
