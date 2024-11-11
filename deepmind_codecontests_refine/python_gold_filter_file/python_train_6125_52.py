a, b, c, d = map(int, input().split())

print('Right' if a+b < c+d else 'Left' if a+b > c+d else 'Balanced')