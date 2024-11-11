n, k = map(int, input().split())
a = list(map(int, input().split()))

sum_energy = sum(a)

l = 0
r = sum_energy
while r - l > 1e-7:
    #print(l, r)
    mid = (l + r) / 2
    ans = 0
    for i in range(n):
        if a[i] > mid:
            ans += (100 - k) / 100 * (a[i] - mid)
        else:
            ans -= mid - a[i]
    if ans >= 0:
        l = mid
    else:
        r = mid
print('%.9f'% l)