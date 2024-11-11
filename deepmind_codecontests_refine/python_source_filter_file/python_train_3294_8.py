t=int(input())
for i in range(t):
    n, k = [int(x) for x in input().split()]
    KrList = [int(x) for x in input().split()]
    maxl=max(KrList[0],n-KrList[-1])
    for K in range(k-1):
        maxl=max(maxl,(KrList[K+1]-KrList[K])//2)
    print(maxl)
