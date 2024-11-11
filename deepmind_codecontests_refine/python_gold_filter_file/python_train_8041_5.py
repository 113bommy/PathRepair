t=int(input())
for i in range(t):
    n=int(input())
    nn=[int(s) for s in input().split()]
    s=0
    ss=0
    for j in range(n):
        if nn[j]%2==0:
            s+=1
            if j%2==0:
                ss+=1
    if s==n%2+n//2:
        print(s-ss)
    else:
        print(-1)