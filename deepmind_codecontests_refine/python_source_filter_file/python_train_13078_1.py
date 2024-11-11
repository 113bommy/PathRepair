def diff(val):
    return 2 * abs(180 - val)


n = int(input())
arr = input().split(' ')
arr = [int(x) for x in arr]

sum = 0
min_diff = 360
last_idx = 0

for a in arr:
    sum += a
    min_diff = min(min_diff, diff(sum))
    if sum > 180:
        sum -= arr[last_idx]
        last_idx += 1
        min_diff = min(min_diff, diff(sum))
    elif sum == 180:
        min_diff = 0
        break

print(min_diff)
