n = int(input())
angka = [7,6,5,4,3,2]

for i in range(n):
    hasil = 0
    dice = int(input())
    for j in angka:
        if dice >= j:
            hasil += dice // j
            dice = dice % j
        if dice == 0:
            break
    print(hasil)

