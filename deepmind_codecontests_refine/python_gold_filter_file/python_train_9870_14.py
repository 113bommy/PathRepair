a, b = map(int, input().split())
print( b if a > 12 else b // 2 if 6 <= a <= 12 else 0 )