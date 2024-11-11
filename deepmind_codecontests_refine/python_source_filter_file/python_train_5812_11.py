l = []
N, T = map(int, input().split())
for i in range(N):
    c, t = map(int, input().split())
    if T > t:
        l.append(c)
print(min(l)if len(l) >= 1 else 'TLE')