n = int(input())
a = sorted([int(input()) for i in range(n)])
l = n//2

if n % 2 == 0:
    small = a[:l]
    big = a[l:]
    ans = sum(big) * 2 - sum(small) * 2  - big[0] + small[-1]
    print(ans)

else:
    small = a[:l]
    big = a[l+1:]
    ans = sum(big) * 2 - sum(small) * 2 - min(n[l] - small[-1], big[0] - n[l])
    print(ans)