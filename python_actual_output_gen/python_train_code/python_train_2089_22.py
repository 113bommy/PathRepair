t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    a=[int(x) for x in input().split()]
    if sum(a)>=m:
        print(m)
    else:
        print(max(a))