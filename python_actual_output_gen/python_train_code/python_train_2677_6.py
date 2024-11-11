t = int(input())

for _ in range(t):
    x,y = map(int,input().split())
    d = x - y
    if d!=1:
        print('NO')
    else:
        print("YES")

