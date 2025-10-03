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

[gambar]

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

[output thingspeak docum]

- **LED**: Menyala jika objek < 10 cm.

[output led nyala < 10 cm docum]

Objek berada di jarak 6.80 cm. **LED** menyala

[output led tidak nyala > 10 cm docum]

Objek berada di jarak 133.74 cm. **LED** mati

> **Catatan:** Pastikan WiFi yang digunakan adalah **2.4 GHz, karena ESP32 tidak mendukung jaringan 5 GHz.
