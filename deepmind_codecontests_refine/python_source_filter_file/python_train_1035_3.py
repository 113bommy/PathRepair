N = int(input())
l = [list(map(int, input().split())) for _ in range(N)]

diff = [0] * 100001
for k in l :
    diff[k[0] - 1] += 1
    diff[k[1]] -= 1

hist = [0,0]
for i in range(2, N + 1) :
    hist.append(hist[-1] + diff[i-1])

print(max([y - 1 for (x,y) in zip(hist, range(N + 1)) if x + 1 >= y]))