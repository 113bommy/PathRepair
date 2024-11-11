import io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
p = [0, 0] + list(map(int, input().split()))
a = [0] + list(map(int, input().split()))

g = [[] for _ in range(n + 1)]
up = [0] * (n + 1)
for i, pi in enumerate(p):
    g[pi].append(i)
    up[pi] += 1

slots = [0] * (n + 1)
cap = [0] * (n + 1)
leaves = [0] * (n + 1)

st = [u for u in range(1, n + 1) if not up[u]]
while st:
    u = st.pop()

    if not g[u]:
        cap[u] = a[u]
        leaves[u] = 1
    else:
        maxcap = cap[max(g[u], key=lambda v: cap[v])]
        slots_sum = 0
        for v in g[u]:
            slots_sum += slots[u] + leaves[v] * (maxcap - cap[v])
            leaves[u] += leaves[v]
        
        mn = min(slots_sum, a[u])
        slots_sum -= mn
        a[u] -= mn

        ausplit = (a[u] + leaves[u] - 1) // leaves[u]
        cap[u] = maxcap + ausplit
        slots[u] = slots_sum + ausplit * leaves[u] - a[u]

    up[p[u]] -= 1
    if not up[p[u]]:
        st.append(p[u])

print(cap[1])
