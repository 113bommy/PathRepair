from collections import defaultdict
S = input()

class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def update(self, i, v):
        while i <= self.n:
            self.bit[i] += v
            i += i & -i
            
    def query(self, i):
        ret = 0
        while i > 0:
            ret += self.bit[i]
            i -= i & -i
            
        return ret

d = defaultdict(list)
for i, v in enumerate(S):
    d[v].append(i + 1)

if sum(len(l) % 2 != 0 for l in d.values()) > 1:
    print(-1)
    exit()

N = len(S)
ctr = []
key_map = [-1] * (N + 1)

for k, v in d.items():
    t = len(v)
    if t % 2  == 1:
        key_map[v[t % 2]] = N // 2 + 1

    for j in range(t // 2):
        ctr.append((v[j], v[-j - 1]))
        
ctr.sort()

for i, (l, r) in enumerate(ctr):
    key_map[l] = i + 1
    key_map[r] = N - i

tree = BIT(N)
ans = 0
for i, v in enumerate(key_map[1:]):
    ans += i - tree.query(v)
    tree.update(v, 1)
print(ans)
