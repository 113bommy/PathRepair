t = int(input())
for e in range(t):
    x,y=map(int,input().split())
    if x==y:
        print("0")
    elif x>y:
        q=x%y
        print(y-q)
    else:
        print(y-x)