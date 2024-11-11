N, M = map(int, input().split())
xs = [[] for _ in range(8)]
for j in range(N):
    a, b, c = map(int, input().split())
    for i in range(2**3):
        t = []
        for k in range(3):
            t.append(1-2*((i>>k)%2))
        xs[i].append(a*t[0] +b*t[1]+c*t[2])
print(max(sum(sorted(xs[i])[-M:]) for i in range(2**3))*(M!=0))
