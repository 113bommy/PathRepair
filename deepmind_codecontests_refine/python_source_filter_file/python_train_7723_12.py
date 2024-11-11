for _ in range(int(input())):
    k = int(input())
    L = list(map(int, input().split()))
    print(L,k)

    L.sort()
    maxSq = 0
    for i in range(k):
        side = L[i]
        left = k-i
        t = min(side, left)
        if maxSq < t:
            maxSq = t
        # print(maxSq)
    print(maxSq)
