from collections import defaultdict
n, m = map(int, input().split())
h = defaultdict(set)
nums = [0] * n
for i in range(m):
    u, v = map(int, input().split())
    h[u].add(v)
    h[v].add(u)

full = 0
one = 0
two = 0
for key, value in h.items():
    if len(value) == n - 1: full += 1
    if len(value) == 1: one += 1
    if len(value) == 2: two += 1
if full == 1 and full + one == n:
    print('star topology')
elif two == n:
    print('ring topology')
elif two == n - 2 and one == 2:
    print('bus topology')

else:
    print('unknown topology')
