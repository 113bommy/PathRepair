n, k = int(input()) - 1, 0
sk = sn = 0
a = [int(i) for i in input().split()]
while k < n:
    if sk <= sn:
        sk += a[k]
        k += 1
    else:
        sn += a[n]
        n -= 1
if sk <= sn:
    k += 1
    n += 1
print(k, len(a) - n)
