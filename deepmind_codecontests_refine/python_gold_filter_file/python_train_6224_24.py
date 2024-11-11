S = input()
N = len(S)

map_ = [-1] * 2019
map_[0] = 0
ans = 0
now = 0
for i in range(0, N):
    now = (now + int(S[N - i - 1]) * pow(10, i, 2019)) % 2019
    map_[now] += 1
    ans += map_[now]

print(ans)
