N, C = map(int, input().split())
programs = [[0 for _ in range(C)] for _ in range(2*10**5)]
for _ in range(N):
    s, t, c = map(int, input().split())
    for i in range(2*s-1, 2*t):
        programs[i][c-1] = 1
ret = 0
for i in range(2*10**5):
    ret = max(ret, sum(programs[i]))
print(ret)
