n = int(input())
for line in range(n):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(float, input().split())
    d = (x2 - x1)*(y4 - y3) - (y2 - y1)*(x4 - x3)
    if -10**-5 <d < 10**-5:
        print('YES')
    else:
        print('NO')