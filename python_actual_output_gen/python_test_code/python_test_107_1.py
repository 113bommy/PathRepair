from itertools import groupby

n = int(input())
s = input()
ans = sum(sum(1 for _ in g) - 2 for k, g in groupby(s) if k == 'x')
print(ans)
