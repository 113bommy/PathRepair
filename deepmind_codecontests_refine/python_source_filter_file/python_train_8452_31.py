t=int(input())
for i in range(t):
    l=list(map(int,input().split()))
    n=l[0];x=l[1];a=min(l[2],l[3]);b=max(l[2],l[3])
    if x<=n-b:
        print(b-a+x)
    else:
        print(n-1)
        
        
