a, b, c = map(int, input().split())
print('Yes' if max(a, b) <= c <= min(a, b) else 'No')