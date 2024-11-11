
x, a, b = map(int, input().split())
print('B' if abs(a-x) < abs(a-b) else 'A')
