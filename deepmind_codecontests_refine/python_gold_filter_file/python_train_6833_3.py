n, k = map(int, input().split())
a = 1
for i in range(n):
    if a * 2 > n:
        a *= 2
        break
    a *= 2
if k == 1:
    print(n)
else:
    print(a - 1)