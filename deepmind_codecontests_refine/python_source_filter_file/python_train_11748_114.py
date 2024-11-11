X,A,B = map(int, input().split())
print('delicious' if A - B >= 0 else 'safe' if abs(A - B) < X else 'dangerous')