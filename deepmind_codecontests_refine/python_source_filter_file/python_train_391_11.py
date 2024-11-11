from collections import defaultdict
N, u, v = map(int, input().split())
d = defaultdict(list)
for _ in range(N-1):
    A, B = map(int, input().split())
    d[A].append(B)
    d[B].append(A)

def get_dist(s):
    dist = [-1]*(N+1)
    dist[s] = 0

    q = [s]
    while q:
        a = q.pop()
        for b in d[a]:
            if dist[b]!=-1:
                continue
            dist[b] = dist[a] + 1
            q.append(b)
    return dist

du, dv = get_dist(u), get_dist(v)
ds = [(i,j[0], j[1]) for i,j in enumerate(zip(du, dv)) if j[0]<j[1]]
ds.sort(key=lambda x:-x[1])
a, b, c = ds[0]
print(c-1)