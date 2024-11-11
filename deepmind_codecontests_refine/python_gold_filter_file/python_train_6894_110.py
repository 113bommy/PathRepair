T=int(input())
for i in range(T):
    n,m=map(int,input().split())
    if(n%m==0):
        print("YES")
    else:
        print("NO")