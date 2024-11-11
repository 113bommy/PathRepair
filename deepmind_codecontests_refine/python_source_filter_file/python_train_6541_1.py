from itertools import accumulate

n,c = map(int, input().split())
stc = [list(map(int, input().split())) for i in range(n)]
finish = [1] * (c+1)
record = [0] * (10 ** 5 + 2) 
ans = 1
for s,t,c in stc:
  if finish[c] != s:
    s -= 1
  finish[c] = t
  record[s] += 1
  record[t] -= 1
ans = max(list(accumulate(record)))
assert ans >= 1
assert ans <= n
print(ans)