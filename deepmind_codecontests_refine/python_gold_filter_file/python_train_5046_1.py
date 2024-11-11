n = int(input())

d = []
s = []
sm = 0
alone = []
for i in range(n):
    de, se = map(int, input().split())
    d.append(de)
    s.append(se)
    if de == 1:
        alone.append(i)
    sm += de

print(sm//2)
while alone:
    v = alone.pop()
    if d[v] == 1:
        print(v, s[v])
        s[s[v]] ^= v
        d[s[v]] -= 1
        if d[s[v]] == 1:
            alone.append(s[v])