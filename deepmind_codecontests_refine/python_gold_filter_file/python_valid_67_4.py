t = int(input())
for i in range(t):
    a,b,c = map(int,input().split())
    p = abs(a-b)
    if a<=(2*p) and b<=(2*p) and c<=(2*p):
        if c>p:
            print(c-p)
        else:
            print(c+p)
    else:
        print(-1)