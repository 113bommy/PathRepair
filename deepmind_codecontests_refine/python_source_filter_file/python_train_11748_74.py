x, a, b = map(int, input().split())
print('delicious' if b <= a else 'safe' if b <= x else 'dangerous')