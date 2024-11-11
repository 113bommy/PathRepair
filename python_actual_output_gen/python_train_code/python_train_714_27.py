a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

if abs(t * (w - v)) >= abs(b - a):
  print('YES')
else:
  print('NO')
