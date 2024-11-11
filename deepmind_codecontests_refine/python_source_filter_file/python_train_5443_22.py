N=int(input())
for i in range(N):
    a,b=map(int,input().split())
    if b%a==0:
        print("YES")
    else:
        print("NO")