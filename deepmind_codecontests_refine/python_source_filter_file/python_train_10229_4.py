T=int(input())
for t in range(0,T):
    a,b,n=map(int,input().split())
    cnt=0
    while max(a,b)<n:
        if a<b:a+=b;
        else:b+=a
        cnt=cnt+1
    print(cnt)