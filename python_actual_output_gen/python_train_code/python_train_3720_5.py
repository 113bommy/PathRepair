q = int(input())
for i in range(q):
    a = list(map(int, input().split()))
    k = a[2]
    if k % 2 == 0:
        print((a[0] + a[1]) * (k // 2))
    else:
        print(a[0] * (k // 2 + 1) + a[1] * (k // 2))



