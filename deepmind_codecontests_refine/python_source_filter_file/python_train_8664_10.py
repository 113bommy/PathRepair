N, M = map(int, input().split())
l = list(map(int, input().split()))

tot = sum(l)
if tot < N or M > N:
    print(-1)
    exit()

diff = tot - N
ans = [1]
for i in range(1, M):
    t = l[i - 1] - 1
    cutin = min(diff, t)
    diff -= cutin
    pos = ans[-1] + l[i - 1] - cutin
    if pos + l[i] > N:
        print(-1)
        exit()
    ans.append(pos)

if diff != 0:
    print(-1)
    exit()

print(" ".join(map(str, ans)))
