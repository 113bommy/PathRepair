n = int(input())
x, y = map(int, input().split())
max_x = min_x = x
max_y = min_y = y
sum_pp = x + y
sum_pn = x - y
sum_np = -x + y
sum_nn = -x - y
for i in range(1, n):
  x, y = map(int, input().split())
  max_x = max(max_x, x)
  min_x = min(min_x, x)
  max_y = max(max_y, y)
  min_y = min(min_y, y)
  if x + y > sum_pp:
    sum_pp = x + y
  if x - y > sum_pn:
    sum_pn = x - y
  if -x + y > sum_np:
    sum_np = -x + y
  if -x - y > sum_nn:
    sum_nn = -x - y
box = 2 * (max_x - min_y + max_y - min_y)
box -= max_x + max_y - sum_pp
box -= max_x - min_y - sum_pn
box -= -min_x + max_y - sum_np
box -= -min_x - min_y - sum_nn
box += 4
print(box)
