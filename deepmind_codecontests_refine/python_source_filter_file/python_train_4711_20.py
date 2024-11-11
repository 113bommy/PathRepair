def coach(n):
    n.sort()
    d=n[1]-n[0]
    e=0
    for i in range(1,N-1):
        if n[i+1]-n[i]<d:
            d=n[i+1]-n[i]
            e=i
    print(d)
    print(n[0:e+1:1],n[e+1:N:1])

T = int(input())
for k in range(T):
    N = int(input())
    A = [int(x) for x in input().split()]
    coach(A)
