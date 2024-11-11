a, b = map(int, input().split())
num = 1
if b > 0:
    if b < a // 2:
        num = b
    else:
        b -= a // 2
        if a & 1 == 1:
            b -= 1
        num = a // 2 - b
print(num)
