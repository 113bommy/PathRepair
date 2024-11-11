import collections
t=int(input())
for _ in range(t):
    [n,k]=[int(i) for i in input().split()]
    x=[int(i) for i in input().split()]
    x.sort(reverse=True)
    freq=collections.Counter(x[0:2*k])
    flag=True
    sm=0
    for (key,value) in freq.items():
        if value>k:
            sm+=(value-k+1)//2
    sm+=sum(x[2*k:])
    print(sm)