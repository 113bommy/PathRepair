def shellsort(a):
    l = len(a)
    gaps = [1]
    while gaps[0]*3+1 < l/9 and len(gaps) <= 100:
        gaps.insert(0, gaps[0]*3+1)
    count = 0
    for g in gaps:
        for i in range(g, l):
            v = a[i]
            j = i-g
            while j >= 0 and v < a[j]:
                a[j+g] = a[j]
                j -= g
                count += 1
            a[j+g] = v

    print(len(gaps))
    print(" ".join([str(n) for n in gaps]))
    print(count)
    print("\n".join([str(n) for n in a]))

shellsort([int(input()) for _ in [None]*(int(input()))])