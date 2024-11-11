a, b = map(int, input().split())
c = 0
while a <= b:
    if str(a)[:2] == str(a)[3:]:
        c += 1
    a += 1
print(c)