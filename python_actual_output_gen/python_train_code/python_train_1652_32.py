X, Y = map(int, input().split())

if Y / 4 <= X and Y % 2 == 0:
    print('Yes')
else:
    print('No')