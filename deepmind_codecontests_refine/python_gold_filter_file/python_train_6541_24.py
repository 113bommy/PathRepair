import itertools
N,C = map(int,input().split())
imos = [0]*(10**6)
info = [list(map(int,input().split())) for i in range(N)]
info = sorted(info,key=lambda x:(x[2],x[0]))
note = -1
before_t = -1
for i in range(N):
    s,t,c = info[i]
    s -= 1
    if c == note and s < before_t:
        s = before_t
    imos[s] += 1
    imos[t] -= 1
    note = c
    before_t = t
acc_sum = list(itertools.accumulate(imos))
ans = max(acc_sum)
print(ans)