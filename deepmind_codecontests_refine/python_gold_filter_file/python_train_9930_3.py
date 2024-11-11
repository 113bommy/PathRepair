from collections import defaultdict

I = lambda: map(int, input().split())

degrees = defaultdict(int)
n, m = I()

for _ in range(m):
    u, v = I()
    degrees[u] += 1
    degrees[v] += 1

values = set(degrees.values())
answer = 'unknown'

if values == {2}:
    answer = 'ring'
elif values == {1, 2}:
    answer = 'bus'
elif values == {1, m}:
    answer = 'star'

print(answer, 'topology')