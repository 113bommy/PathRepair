N,M=map(int,input().split())
if N%2==1:
    for i in range(1,M+1):
        a,b=i,N-i+1
        print(a,b)
else:
    t=0
    for i in range(1,M+1):
        a,b=i,N-i
        if (a-1)+(N+1-b)>=b-a:
            t=1
        a+=t
        print(a,b)