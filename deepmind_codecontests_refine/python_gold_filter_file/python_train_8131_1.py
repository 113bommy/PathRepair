n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
i = 0
s = 0
c = 0
while c < k:
    if i < n:
        if a[i] - s > 0:
            print(a[i] - s)
            s += a[i] - s
        else:
            i += 1
            continue
        i += 1
        
    else:
        print(0)
    c += 1
        
        