#1030B
[n,d] = list(map(int,input().split()))
m = int(input())
for i in range(m):
    [x,y] = list(map(int,input().split()))
    if y <= x+d and y >= -x +2 and y >= x-d and y <= -x +2*n-d:
        print('YES')
    else:
        print('NO')