from itertools import *
def count_inversion(sequence):
    return sum(sum(m<n for m in sequence[i+1:]) for i,n in enumerate(sequence))

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

up = []
down = []
for i in range(n):
    if i % 2 == 0:
        up.append((a[i], i))
        down.append((b[i], i))
    else:
        up.append((b[i], i))
        down.append((a[i], i))

up.sort()
l = set([i for i in range(n)])

ans = 100
for u in combinations(up, (n+1)//2):
    index = []
    value = []
    for val, ind in u:
        index.append(ind)
        value.append(val)

    d_index = l - set(index)
    d = []
    for i in d_index:
        d.append(down[i])
    d.sort()
    value.append(100)
    flag = 1
    for i in range(len(d)):
        if not value[i] <= d[i][0] <= value[i+1]:
            flag = 0
            break
    if flag == 0:
        continue

    for i in range(len(d)):
        index.insert(2*i+1, d[i][1])

    ans = min(ans, count_inversion(index))



if ans == 100:
    print(-1)
else:
    print(ans)
