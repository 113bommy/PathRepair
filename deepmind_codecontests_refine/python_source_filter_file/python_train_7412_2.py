#a = list(map(int, input().split()))

t = int(input())

for i in range(t):
    a, b = map(int, input().split())
    x = 2 * b - a
    y = 2 * a - b
    if(x % 3 != 0) and (y % 3 != 0):
        print('NO')
        continue
    if(x < 0 and y < 0):
        print('NO')
        continue
    print('YES')

