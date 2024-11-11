a, b, c, d = map(int, input().split())
l, r = a + b, c + d
print('Left' if l > r else 'Balanced' if l == r else 'Right')
  
