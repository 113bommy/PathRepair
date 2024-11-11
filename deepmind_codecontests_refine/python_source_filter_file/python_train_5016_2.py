n, k = map(int, input().split())
s = [0] * n
for i, v in enumerate(map(int, input().split())):
    s[v-1] = i
t = [0] * n
for i, v in enumerate(map(int, input().split())):
    t[v-1] = i
p = [0] * n
for u, v in zip(s, t):
    if u == v: continue
    elif v < u: u, v = v, u
    p[u-1] += 1
    p[v-1] -= 1
r = [0] * n
cur = 0
nxt = -1
for i, v in enumerate(p):
    if cur == 0 and nxt < 25: nxt += 1
    r[i] = nxt
    cur += v
 
if nxt < k-1:
    print("NO")
else:
    print("YES")
    print("".join(map(lambda x: chr(ord('a')+r[x-1]), s)))

