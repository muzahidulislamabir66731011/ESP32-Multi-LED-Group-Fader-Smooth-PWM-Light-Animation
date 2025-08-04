# 🌈 ESP32 Multi-LED Group Fader – Smooth PWM Light Animation

Create beautiful, wave-like LED animations using high-frequency PWM on the ESP32. This sketch fades multiple LEDs in synchronized groups for a mesmerizing visual effect.

---

## 🔌 GPIO Pin Mapping

| LED Color | GPIO Pin | ESP32 Label | Resistor | Notes                       |
|-----------|----------|-------------|----------|-----------------------------|
| Red       | GPIO 2   | G2          | 220Ω     | Anode (+) to GPIO pin       |
| Yellow    | GPIO 4   | G4          | 220Ω     |                             |
| Green     | GPIO 5   | G5          | 220Ω     |                             |
| Blue      | GPIO 15  | G15         | 220Ω     |                             |
| White     | GPIO 18  | G18         | 220Ω     | Can be used for blinking    |

---

## 🛠️ Setup Instructions

1. Insert all 5 LEDs into your breadboard.
2. Connect the **anode (+)** of each LED to its corresponding GPIO pin through a **220Ω resistor**.
3. Connect all **cathodes (–)** to the **GND rail** of the breadboard.
4. Connect the **GND rail** to any **GND pin** on the ESP32.
5. Upload the `ESP32_PWM_LED_Group_Fader.ino` sketch via Arduino IDE or PlatformIO.
6. Power on and watch LEDs fade in groups!

---

## ✨ Group Fading Behavior

| Group     | LED Colors           | Channels Fading Together       |
|-----------|----------------------|--------------------------------|
| Group 1   | Green                | Single LED fade                |
| Group 2   | Blue, Yellow         | Dual LED fade                  |
| Group 3   | White, Red           | Dual LED fade                  |
| Group 4   | Blue, Yellow         | Repeats Group 2 for loop flow  |

Each group fades in from 0–255 brightness and then fades out, creating a seamless, rhythmic animation.

---

## ⚙️ PWM Configuration

- **Frequency**: 50,000 Hz (flicker-free for human eyes)
- **Resolution**: 8-bit (0–255 brightness)
- **PWM Channels Used**: 0–4 (one per LED)

---

## 📃 License

MIT License — feel free to use, modify, and share.

---

## 💡 Tips & Ideas

- Increase the delay to slow down the fade or decrease it for faster animations.
- Swap or expand the groups to create your own unique patterns.
- Upgrade to 12-bit resolution for smoother transitions (`ledcSetup(..., ..., 12)`).

---
