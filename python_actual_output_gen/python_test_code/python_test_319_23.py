n,a,b=map(int,input().split())

if (b-a)%2==0:
    print((b-a)//2)
else:
    print(min((b+a-1)//2),(2*n-a-b+1)//2)