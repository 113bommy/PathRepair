n, m, k = map(int, input().split())
k += 1
dead = [0] * n  # time of deadlock
block = [False] * k  # ceil is blocked
t = [tuple(map(int, input().split())) for i in range(n)]
for j, s in enumerate(zip(*t), 1):
    q = [[] for i in range(k)]
    for core, ceil in enumerate(s):
        if dead[core] == 0: q[ceil].append(core)
    for ceil in range(1, k):
        if not q[ceil]: continue
        if block[ceil] or len(q[ceil]) > 1:
            for core in q[ceil]: dead[core] = j
            block[ceil] = True
print('\n'.join(map(str, dead)))