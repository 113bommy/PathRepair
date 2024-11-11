N, M = map(int, input().split())
A = list(map(int, input().split()))
magic = [list(map(int, input().split())) for _ in range(M)]
magic = sorted(magic, key=lambda x: -x[0])

hold = []
now = 0
for k, v in magic:
    hold.extend([v]*k)
    now += k
    if now >= N:
        break
A.extend(hold)
A.sort(reverse=True)
print(sum(A[:N]))
