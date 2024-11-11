a, b = map(int, input().split())
x = a
y = b
count = 1
for i in range(11):
  x += x*3
  y += y*2
  if x > y:
    break
  else:
    count += 1
print(count)