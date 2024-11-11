for _ in range(int(input())):
    n = int(input())
    k = [int(j) for j in input().split()]
    t = 0
    maxx=-1
    for j in range(n-1,-1,-1):
        t = t + k[j]
        if maxx<t:
            maxx=t
    print(maxx)
        