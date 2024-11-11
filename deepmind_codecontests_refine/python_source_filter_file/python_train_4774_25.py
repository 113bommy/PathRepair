from collections import defaultdict

N, Ma, Mb = map(int, input().split())
M = [tuple(map(int, input().split())) for _ in range(N)]

d = defaultdict(lambda: float('inf'))
d[(0, 0)] = 0
for a, b, c in M:
    new_d = d.copy()
    for key_a, key_b in d:
        new_d[(a + key_a, b + key_b)] = min(new_d[(a + key_a, b + key_b)],
                                            new_d[(key_a, key_b)] + c)
    d = new_d

ans = float('inf')
for i in range(1, 401 // max(Ma, Mb)):
    ans = min(ans, d[(Ma * i, Mb * i)])
print(ans if ans != float('inf') else -1)
