b = list(map(int, input().split()))
i = 0
for i in range(b[1]):
    if b[0] % 10 == 0:
        b[0] = b[0] / 10
    else:
        b[0] = b[0] - 1
print(b[0])
