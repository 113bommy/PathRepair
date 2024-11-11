a, b, c = map(int, input().split())
print('Yes' if a <= c <= b or a >= b >= c else 'No')