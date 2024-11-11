def solve():
    ans = []
    for i, (x, y) in enumerate(s):
        if num[x]>num[y]: x, y = y, x
        if num[x]==num[y] and i < n-1:
            if y == s[i+1][0] or y == s[i+1][1]:
                x, y = y, x
        num[x]+=1
        num[y]-=1
        ans.append(x)
        if num[y]<0: return False
    return True
from collections import defaultdict
import sys
n, a, b, c = map(int, input().split())
num = defaultdict(int)
s = [input() for _ in range(n)]
num['A'] = a
num['B'] = b
num['C'] = c
id = ['A', 'B', 'C']
ans = solve()
if ans:
    print('Yes')
    print(*ans, sep = '\n')
else:
    print('No')