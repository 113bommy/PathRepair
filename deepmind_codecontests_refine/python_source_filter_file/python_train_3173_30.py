n, k = [int(x) for x in input().split()]

a = [int(x) for x in input().split()]

mn = min(a)
mx = max(a)

if mx - mn > k - 1:
    print("NO")
else:
    print("YES")
    for i in range(n):
        for j in range(a[i]):
            l = [1] * a[i]
            for p in range(mn, a[i]):
                l[p] += l[p-1]
        print(" ".join(str(x) for x in l))
