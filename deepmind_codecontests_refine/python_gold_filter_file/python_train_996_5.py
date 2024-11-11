rick = [bool(0)] * 100001
morty = [bool(0)] * 100001
a, b = input().split(' ')
a = int(a)
b = int(b)
c, d = input().split(' ')
c = int(c)
d = int(d)
i = int(1)
krick = -1
rick_krick = b
morty_krick = d
while rick_krick <= 10000:
    rick[rick_krick] = 1
    rick_krick += a
while morty_krick <= 10000:
    morty[morty_krick] = 1
    morty_krick += c
while krick == -1 and i <= 10000:
    if morty[i] == 1 and rick[i] == 1:
        krick = i
    i += 1
print(krick)
