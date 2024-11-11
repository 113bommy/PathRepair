t=int(input())
for i in range(t):
    a,b=map(int,input().strip().split())
    if a==2*b:
        print("YES")
    else:
        print("NO")
