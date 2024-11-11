count = 0 #Счетчик прошедших укладок
razmery = input() #Введите длину и ширину доски
massiv = razmery.split()
m = int(massiv[0])
n = int(massiv[1])
i = 2 * 1 #Размеры доминошки
s = m * n #Площадь доски
while i < s:
    if i < s:
        count += 1
        i = i + 2
print(count)