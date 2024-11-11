a, b, c, d = map(int, input().split())
print('yes' if abs(a-c) <= d or (abs(a-b) <= d and abs(b-c) <= d) else 'No')