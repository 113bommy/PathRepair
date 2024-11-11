t = int(input())

for i in range(t):
    a,b,c,d = map(int,input().split())
    if (b-a) % (c+d):
        print((b-a)//(c+d))
    else:
        print(-1)