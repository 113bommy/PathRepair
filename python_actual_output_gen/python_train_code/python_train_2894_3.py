n, x = map(int, input().split(" "))
list_a = list(map(int, input().split(" ")))
count = 0
last = 0
for a in list_a:
  act = max(0, last + a - x)
  last = x - last
  count += act
print(count)