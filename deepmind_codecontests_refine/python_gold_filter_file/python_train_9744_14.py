import sys
n,k=map(int,input().split())
L=list(map(int,input().split()))

s=sum(L)
i=0
while 1:
    y=(i*k+s)/(n+i)
    if y<=k and (k-y)<=0.5:
        print(i)
        sys.exit(0)
    elif y>k and (y-k)<0.5:
        print(i)
        sys.exit(0)
    i+=1
    
