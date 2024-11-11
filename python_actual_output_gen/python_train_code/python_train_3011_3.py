X, Y = map(int, input().split())
if abs(X - Y) % 2 == 1:
    print('Brown')
else:
    print('Alice')
