x, a, b = map(int, input().split())
print('B' if abs(b-x) < abs(b-a) else 'A')