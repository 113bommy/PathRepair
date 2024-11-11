n = int(input())

t = [i * i for i in range(100)]
mi = 0
for _ in range(n):
    tmp = input().split()[1]
    if tmp == 'soft':
        mi += 1

mi = min(mi,n - mi)
max = max(mi,n - mi)
if max == 1:
    print(n)
else:
    for i in range(99):
        if (t[i] // 2 + t[i] % 2) < max <= (t[i + 1] // 2 + t[i + 1] % 2):
            print(i + 1)
            break