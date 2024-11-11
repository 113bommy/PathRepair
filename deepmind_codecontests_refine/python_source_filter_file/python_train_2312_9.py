import sys
input = sys.stdin.readline
for t in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    if n < 8:
        print(0, 0, 0)
        continue
    b = [0]
    for i in range(1, n):
        if a[i] != a[i - 1]:
            b.append(b[i - 1] + 1)
        else:
            b.append(b[i - 1])
    k = n // 2 - 1
    if b[k] == b[k + 1]:
        while k > 0 and b[k] == b[k + 1]:
            k -= 1
    if k < 5:
        print(0, 0, 0)
        continue
    p = 0
    while p <= k and a[p] == a[p + 1]:
        p += 1
    p += 1
    q = p
    while q <= k:
        if p < q - p and a[q] != a[q + 1]:
            break
        q += 1
    q += 1
    k += 1
    q = q - p
    k = k - p - q
    if p < q and p < k:
        print(p, q, k)
    else:
        print(0, 0, 0)
