S, N = 2505, 105
m = 1000000007
k = 26
p = [[0] * (S + k) for i in range(N)]
p[0][0] = 1
for n in range(1, N):
    for s in range(S):
        p[n][s] = (p[n][s - 1] + p[n - 1][s] - p[n - 1][s - k]) % m
r = []
for j in range(int(input())):
    t = input()
    s = sum(ord(q) - 97 for q in t)
    print(p[len(t)][s] - 1)
