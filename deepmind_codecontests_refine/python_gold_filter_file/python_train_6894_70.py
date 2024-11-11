t=int(input())

for i in range(0,t):
    n,m=map(int,input().split())
    if(n%m==0):
        print("Yes")
    else:
        print("No")