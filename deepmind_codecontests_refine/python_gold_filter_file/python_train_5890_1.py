n = int(input())
v = list(input())

from collections import deque
d = deque()

cur = 'X'
cnt = 0

for i in range(n):
    if v[i] == cur:
        cnt += 1
    else:
        if cnt > 0:
            d.append((cur, cnt))
        cur = v[i]
        cnt = 1

if cnt > 0:
    d.append((v[-1], cnt))

#print(d)

while len(d) > 1:
    v = d.popleft()
    v2 = d.popleft()

    if v[0] == v2[0]:
        d.appendleft((v[0], v[1] + v2[1]))
    else:
        if v[1] >= v2[1]:
            if v[1] > v2[1]:
                d.appendleft((v[0], v[1] - v2[1]))
            d.append((v[0], v2[1]))
        else:
            d.appendleft((v2[0], v2[1] - v[1]))
            d.append((v[0], v[1]))

    #print(d)

print(d.pop()[0])

