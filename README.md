# IOT-ESP32-LED-Jarak

## Ultrasonic Distance Monitoring with ESP32 + ThingSpeak

### Deskripsi 

Project ini menggunakan **ESP32 DevKit V1**, **sensor ultrasonik HC-SR04**, dan **LED** untuk mengukur jarak.
Apabila jarak < 10 cm, maka LED akan menyala.
Selain itu, hasil pengukuran jarak akan dikirim secara otomatis ke **ThingSpeak** untuk monitoring jarak secara online.

## Kebutuhan Alat

- 1x ESP32 DevKit V1
- 1x Sensor Ultrasonic HC-SR04
- 1x LED
- 1x Resistor 220Ω (untuk LED)
- Kabel jumper + Breadboard
- WiFi 2.4 GHz

## Rangkaian

![image alt](https://github.com/sipalingnub/IOT-ESP32-LED-Jarak/blob/86d697e04bc03e34f7ecb3343ba6e2d22e4f3c9c/assets/WhatsApp%20Image%202025-10-03%20at%2010.34.15.jpeg)

- Ultrasonik:

```VCC → 5V ESP32

GND → GND ESP32

TRIG → GPIO 5

ECHO → GPIO 18
```

- LED:

```Anoda (+) → GPIO 2 melalui resistor 220Ω

Katoda (–) → GND
```

## Cara Kerja

1. ESP32 membaca jarak dari sensor ultrasonik.
2. Jika jarak < 10 cm -> LED menyala (indikasi objek dekat).
3. Data jarak dikirim ke ThingSpeak setiap 15 detik.
4. Data bisa dipantau secara real-time pada dashboard ThingSpeak.

## Kode Program

[kode]

## Output 

- **Serial Monitor:** Menampilkan jarak dalam cm dan status pengiriman ke ThingSpeak.

![image alt](https://github.com/sipalingnub/IOT-ESP32-LED-Jarak/blob/86d697e04bc03e34f7ecb3343ba6e2d22e4f3c9c/assets/WhatsApp%20Image%202025-10-03%20at%2010.31.22.jpeg)

- **LED**: Menyala jika objek < 10 cm.

![image alt](https://github.com/sipalingnub/IOT-ESP32-LED-Jarak/blob/86d697e04bc03e34f7ecb3343ba6e2d22e4f3c9c/assets/WhatsApp%20Image%202025-10-03%20at%2010.29.37.jpeg)

Objek berada di jarak 6.80 cm. **LED** menyala

![image alt](https://github.com/sipalingnub/IOT-ESP32-LED-Jarak/blob/86d697e04bc03e34f7ecb3343ba6e2d22e4f3c9c/assets/WhatsApp%20Image%202025-10-03%20at%2010.30.51.jpeg)

Objek berada di jarak 133.74 cm. **LED** mati

> **Catatan:** Pastikan WiFi yang digunakan adalah **2.4 GHz, karena ESP32 tidak mendukung jaringan 5 GHz.
