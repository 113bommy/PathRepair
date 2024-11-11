for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = a[::-1]
    amaxx = max(a)
    aminn = min(a)
    if aminn == amaxx:
        print(-1)
        continue
    am = a.index(amaxx)
    bm = b.index(amaxx)
    if a[0] == amaxx:
        ind = 1
        while True:
            if a[ind] < amaxx:
                print(ind-1)
                break
            ind += 1
        continue

    else:
        print(am)
