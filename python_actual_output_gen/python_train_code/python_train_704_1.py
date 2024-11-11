n, k = map(int, input().split())
a = list(map(int, input().split()))
tot = 0
nn = n
ii = 1
for i in range(n):
    di = tot - (nn-ii)*a[i]
    if i == 0:
        di = 0
    # print(i, di)
    if di < k:
        print(i+1)
        nn -= 1
    else:
        tot += a[i]*(ii-1)
        ii += 1
