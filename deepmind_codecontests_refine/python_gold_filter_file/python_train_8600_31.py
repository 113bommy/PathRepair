a = [-1] * 16
a[0] = 0
for i in range(1,16):
    for j in [4, 6, 9]:
        if i >= j and a[i - j] != -1:
            a[i] = max(a[i], a[i - j] + 1)

for _ in range(int(input())):
    n = int(input())
    if n < 16:
        print(a[n])
    else:
        t = (n - 16) // 4 + 1
        print(a[n - t * 4] + t)