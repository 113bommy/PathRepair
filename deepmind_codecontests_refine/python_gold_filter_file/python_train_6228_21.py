n, m, X, Y = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

if max(x+[X]) < min(y+[Y]):
    print('No War')
else:
    print('War')
