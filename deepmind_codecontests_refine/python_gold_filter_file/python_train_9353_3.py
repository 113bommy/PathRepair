N, L, T = map(int, input().split())
n = [list(map(int, input().split())) for _ in range(N)]
t = [X + (0, T, -T)[W] for X, W in n]
l = sorted(i % L for i in t)
s = sum(i // L for i in t) % N
for i in l[s:] + l[:s]: print(i)