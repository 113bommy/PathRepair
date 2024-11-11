s, l = map(int, input().split())
t = []
for i in range(l, 0, -1):
    k = i ^ (-i)
    if s >= k:
        t.append(str(i))
        s -= k
print(-1 if s else str(len(t)) + '\n' + ' '.join(t))