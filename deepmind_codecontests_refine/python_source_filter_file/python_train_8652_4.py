def arr_inp():
    return [int(x) for x in stdin.readline().split()]


from sys import stdin
from collections import Counter, deque
from math import ceil

n, k = arr_inp()
s = arr_inp()
mem = Counter(s).most_common()
if k > n // 2 or mem[0][1] == 1:
    exit(print(*[s[i] for i in range(k)]))

if len(mem) == 1:
    exit(print(*[mem[0][0] for i in range(k)]))

diff, p1, ans, total, tem = mem[0][1] / k, 1, [], mem[0][1], deque([mem[0]])
while (p1 < len(mem) and diff <= mem[p1][1]):
    diff += mem[p1][1] / k
    tem.append(mem[p1])
    total += mem[p1][1]
    p1 += 1

for i in range(len(tem)):
    num = ((tem[0][1] / total) * k)
    if num - .5 >= int(num):
        num = ceil(num)
    else:
        num = int(num)
    ans.extend([tem[0][0] for j in range(num)])
    tem.rotate(-1)

print(*ans)
