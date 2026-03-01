# Kelompok-3-Iot-Cyber-Physical-System
🌦️ Smart Clothesline (Jemuran Pintar Berbasis ESP32-S3)
📌 Deskripsi Proyek

Smart Clothesline adalah sistem jemuran otomatis berbasis ESP32-S3 yang dapat mendeteksi hujan/gerimis dan suhu lingkungan secara real-time.

Sistem ini menggunakan:

🌧️ Sensor Raindrop untuk mendeteksi air/hujan

🌡️ Sensor Suhu Analog untuk membaca suhu sekitar

⚙️ Servo Motor untuk memindahkan jemuran secara otomatis

💡 LED Two Color (Merah & Hijau) sebagai indikator status cuaca

Jika terdeteksi hujan, jemuran akan otomatis berpindah ke tempat yang tidak terkena hujan. Jika tidak ada hujan, jemuran tetap di posisi awal.

🔁 Alur Sistem (Sesuai Flowchart)

Berikut adalah alur kerja sistem berdasarkan diagram yang diberikan:

Sistem Menyala

ESP32-S3 membaca Sensor Raindrop

Sistem mengecek:

Apakah terdeteksi air/hujan?

➤ Jika TIDAK (NO):

Servo tetap di posisi awal

LED Hijau ON (menandakan tidak hujan)

Sensor suhu dibaca

Data suhu ditampilkan / dimonitoring

Selesai

➤ Jika YA (YES):

Servo bergerak (jemuran masuk/berpindah)

LED Merah ON (menandakan hujan/gerimis)

Sensor suhu dibaca

Data suhu ditampilkan / dimonitoring

Selesai

🧩 Komponen yang Digunakan

ESP32-S3

Sensor Raindrop

Sensor Suhu Analog (misalnya LM35 / NTC)

Servo Motor

LED Merah

LED Hijau

Resistor pendukung

Power Supply

⚙️ Cara Kerja Sistem
🌧️ 1. Deteksi Hujan (Sensor Raindrop)

Sensor mendeteksi adanya air.

Jika nilai melebihi threshold → dianggap hujan.

Sistem mengaktifkan servo untuk memindahkan jemuran.

🌡️ 2. Monitoring Suhu (Analog Temperature Sensor)

Sensor membaca suhu sekitar.

Data dikonversi dari analog ke suhu (°C).

Ditampilkan pada Serial Monitor / Display (jika digunakan).
