n = int(input())

flag = 0
for _ in range(n):
  t, x, y = map(int, input().split())
  if t%2 == (x+y)%2 and t >= (x+y):
    continue
  else:
    flag = 1
    
print('YES') if not flag else print('NO')