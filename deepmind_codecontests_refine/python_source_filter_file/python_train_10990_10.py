m, d = map(int, input().split())
q = 0
if m <= 7:
    q = 30 + (m % 2)
else:
    q = 31 - (m % 2)
if m == 4:
    q = 28
p = q - 28
if (p > 8 - d):
    print(6)
elif p == 0 and d == 1:
    print(4)
else:
    print(5)