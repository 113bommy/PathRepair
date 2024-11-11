t=int(input())
for _ in range(t):
    x,y=map(int,input().split())
    r=x%y
    if(r==0):
        print(y)
    else:
        print(y-r)
