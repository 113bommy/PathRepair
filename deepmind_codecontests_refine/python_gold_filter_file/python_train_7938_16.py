n,m,x,y = map(int,input().split())
x -= 1
y -= 1
for _ in range(n):
    for i in range(m-1):
        print(x+1,y+1)
        y += 1
        y %= m
    print(x+1,y+1)
    x += 1
    x %= n

