t=int(input())
while(t>0):
    x,y=map(int,input().split())
    if x%y==0:
        print("YES")
    else:
        print("NO")
    t-=1