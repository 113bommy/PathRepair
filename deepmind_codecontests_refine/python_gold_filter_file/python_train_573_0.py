a, b, c = map(int, input().split())
for i in range(0, 10000):
    if (i * a > c):
        break
    if (c - i * a) % b == 0:
        print("Yes")
        exit()
print("No")