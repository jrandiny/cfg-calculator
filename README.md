# Calculator

Sebuah program kalkulator sederhana untuk menghitung

## Fitur dan Limitasi

### Fitur

- Mendukung bilangan desimal dan bulat (positif dan negatif)
- Mendukung  tambah, kali, bagi, kurang, serta pangkat
- Mendukung penggunaan tanda kurung untuk prioritas eksekusi

### Limitasi

- Tidak mendukung variabel
- Tidak mendukung imajiner

## Menjalankan

Compile dengan menggunakan library readline

```
gcc main.c parser.c -o calculator -lm -lreadline
```

Catatan : Untuk selain linux, tidak membutuhkan flag -lreadline

Setelah dicompile, jalankan seperti biasa

```
./calculator
```

Akan terlihat prompt, isi ekspresi matematika yang diinginkan, lalu tekan enter

```
>> 1+3 <enter>
>> 4.00
```

Perlu diingat, untuk memasukkan bilangan negatif, harap ditulis dalam tanda kurung