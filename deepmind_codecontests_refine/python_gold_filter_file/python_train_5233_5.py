t=int(input())
while(t>0):
    a,b=map(int,input().split())
    if 2*a<=b:
        print(a,2*a)
    else:
        print(-1,-1)
    t-=1