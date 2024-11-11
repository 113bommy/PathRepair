a=int(input())
for i in range(a):
    x,y=map(int,input().split())
    if(x%y==0):
        print("YES")
    else:
        print("NO")