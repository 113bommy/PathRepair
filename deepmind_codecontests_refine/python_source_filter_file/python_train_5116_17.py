from collections import deque


m, n = map(int, input().split())
bottles = deque(list(map(int, input().split())))
chosen = []
sum = 0
while bottles and sum < 2*n:
    chosen.append(bottles.popleft())
    sum += chosen[-1]
if sum > 2 * n:
    chosen.pop()
tmp = chosen.copy()
while True:
    chosen = tmp.copy()
    chosen.sort()
    count = len(chosen)
    h = 0
    while chosen and h < n:
        if len(chosen) == 1:
            x = chosen.pop()
            h += x
        else:
            x = chosen.pop()
            y = chosen.pop()
            h += max(x, y)
    if len(chosen) != 0:
        tmp.pop()
    else:
        print(count)
        break
