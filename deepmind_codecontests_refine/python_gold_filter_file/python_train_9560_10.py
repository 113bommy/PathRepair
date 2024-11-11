a, b = map(int, input().split())
c = 0
while a <= b:
    if str(a) == str(a)[::-1]:
        c += 1
    a += 1
print(c)