t = int(input())
for i in range(t):
    x,y,a,b = map(int,input().split())
    g =(y-x)/(a+b)
    if g==(y-x)//(a+b):
        print(g)
    else:
        print("-1")