t = int(input())
for e in range(t):
    x,y=map(int,input().split())
    if x%y==0:
        print("0")
    elif x>y:
        q=x%y
        print(x-q)
    else:
        print(y-x)