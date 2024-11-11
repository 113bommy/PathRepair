from math import ceil
from decimal import *

guys, add_guys, max_diff = map(int, input().split())
arr = sorted(list(map(int, input().split())))
diff_arr = list()
for ind in range(1, guys):
    if arr[ind] - arr[ind - 1] > max_diff:
        our_num = Decimal((Decimal(arr[ind]) - (Decimal(arr[ind - 1]))) / Decimal(max_diff))
        our_num = ceil(Decimal(our_num))
        diff_arr.append(our_num)
diff_arr = sorted(diff_arr)
ans = len(diff_arr) + 1
for ind in range(0, len(diff_arr)):
    if add_guys - diff_arr[ind] >= 0:
        add_guys -= diff_arr[ind]
        ans -= 1
    else:
        break
print(ans)
