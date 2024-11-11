from itertools import permutations

n, m = map(int, input().split())
paths = set()

for i in range(n) :
    _a, _b = map(int, input().split())
    paths.add((_a, _b))
    paths.add((_b, _a))
    
# print(sum(all(s in paths for s in zip((1,) + p, p)) for p in permutations(range(2, n + 1))))

