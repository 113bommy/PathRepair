a, b, c, d = map(int, input().split())
print('No' if abs(c-a) <= d or (abs(b-a) <= d and abs(c-b) <= d) else 'Yes')
