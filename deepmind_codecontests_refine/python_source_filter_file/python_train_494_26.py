from collections import defaultdict
from math import gcd

MOD = 10 ** 9 + 7
N = int(input())
AB = []
NUMS = defaultdict(int)
zeros = 0
for _ in range(N):
    a, b = map(int, input().split())
    AB.append((a, b))

    if a == b == 0:
        zeros += 1
        continue

    d = gcd(a, b)
    x, y = a // d, b // d
    if y < 0:
        x, y = -x, -y
    NUMS[x, y] += 1

todo = set(NUMS.keys())
ans = 1
while todo:
    x, y = todo.pop()
    if (-y, x) in todo or (y, -x) in todo:
        assert not ((-y, x) in todo and (y, -x) in todo)
        if (-y, x) in todo:
            v = NUMS[-y, x]
        else:
            v = NUMS[y, -x]
        ans = ans * (2 ** NUMS[x, y] + 2 ** v - 1) % MOD
        todo -= {(-y, x), (y, -x)}
    else:
        ans = ans * (2 ** NUMS[x, y]) % MOD
ans += zeros - 1
print(ans)