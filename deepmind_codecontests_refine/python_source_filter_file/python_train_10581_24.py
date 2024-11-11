n, m = map(int, input().split())
cena = 10000
for i in range(0, n):
    a, b = map(int, input().split())
    novcena = a / b
    if novcena < cena:
        cena = novcena
print(novcena * m)
