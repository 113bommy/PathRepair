from collections import *

s, ans, arr = input(), 0, []
d = deque([[i, s[i - 1]] for i in range(1, len(s) + 1)])

while (True):
    tem1 = []
    while (d):
        if d[0][1] == '(':
            while (d):
                if d[-1][1] == ')':
                    tem1.append(d[0][0])
                    tem1.append(d[-1][0])
                    d.pop()
                    break
                d.pop()

            if d:
                d.popleft()

        else:
            d.popleft()

    if tem1:
        arr.append(tem1)
    else:
        break

print(len(arr))
for i in arr:
    print(len(i))
    print(*sorted(i))
