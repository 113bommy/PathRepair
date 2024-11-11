N = int(input())
s = [input() for _ in range(N)]

M = int(input())
t = [input() for _ in range(M)]

ans = [s.count(si) - t.count(si) for si in set(s)]

print(max(ans))
