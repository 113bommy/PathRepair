T=int(input())
for a in range(T):
    x,y=map(int,input().split())
    if(x-y)!=1:
        print("YES")
    else:
        print("NO")
