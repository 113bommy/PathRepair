t=int(input())
for _ in range(t):
    n,s=map(int,input().split())
    a=list(map(int,input().split()))
    if sum(a)<=s:
        print(0)
        continue
    mx=0
    sm=0
    end=-1
    for i in range(n):
        sm+=a[i]
        if a[i]>a[mx]:
            mx=i
        if sm>s:
            end=i
            break
    print(mx+1)
