# **Smart Clothesline (Jemuran Pintar Berbasis ESP32-S3)**


Deskripsi Proyek
Smart Clothesline adalah sistem jemuran otomatis berbasis ESP32-S3 yang dapat mendeteksi hujan/gerimis dan suhu lingkungan secara real-time.

1. Sensor Raindrop untuk mendeteksi air/hujan
2. Sensor Suhu Analog untuk membaca suhu sekitar
3. Servo Motor untuk memindahkan jemuran secara otomatis
4. LED Two Color (Merah & Hijau) sebagai indikator status cuaca


**Komponen yang Digunakan**

1. ESP32-S3
2. Sensor Raindrop
3. Sensor NTC
4. Servo 
5. RGB LED
8. Power Supply


**Cara Kerja Sistem**

**1. Deteksi Hujan (Sensor Raindrop)**
- Sensor mendeteksi adanya air.

- Jika nilai melebihi threshold maka dianggap hujan.

- Sistem mengaktifkan servo untuk memindahkan jemuran.

**2. Monitoring Suhu (Analog Temperature Sensor)**
- Sensor membaca suhu sekitar.

- Data dikonversi dari analog ke suhu (°C).

- Ditampilkan pada Serial Monitor / Display (jika digunakan).

- Jika terdeteksi hujan, jemuran akan otomatis berpindah ke tempat yang tidak terkena hujan. Jika tidak ada hujan, jemuran tetap di posisi awal.

  

**Alur Sistem :**



- Sistem Menyala

- ESP32-S3 membaca Sensor Raindrop

- Apakah terdeteksi air/hujan?

**Jika TIDAK :**

- Servo tetap di posisi awal

- LED Hijau ON (menandakan tidak hujan)

- Sensor suhu dibaca

- Data suhu ditampilkan / dimonitoring

- Selesai

**Jika YA :**

- Servo bergerak (jemuran masuk/berpindah)

- LED Merah ON (menandakan hujan/gerimis)

- Sensor suhu dibaca

- Data suhu ditampilkan / dimonitoring

- Selesai

