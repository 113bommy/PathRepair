t=int(input())
for _ in range(0,t):
    a,b,n=list(map(int,input().split()))
    if(n==0):
        print(a)
    elif(n==1):
        print(b)
    else:
        print(a^b)