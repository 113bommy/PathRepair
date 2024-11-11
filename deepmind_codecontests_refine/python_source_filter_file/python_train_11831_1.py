S = input()
Glas = [97, 101, 105, 111, 117]
k = 0
for i in S:
    if ord(i) in Glas:
        k += 1
    if 58 > ord(i) > 47:
        if int(i) % 2 == 0:
            k += 1
print(k)