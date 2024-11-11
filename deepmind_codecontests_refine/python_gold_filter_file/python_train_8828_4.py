N, M = (int(i) for i in input().split()) 

outs = [[] for i in range(N)]
ins = [0] * N

for _ in range(M):
    x, y = (int(i) for i in input().split())
    x -= 1
    y -= 1
    outs[x].append(y)
    ins[y] += 1

q = []
for i in range(N):
    if ins[i] == 0:
        q.append(i)

last = [0] * N
while q != []:
    qn = q.pop()
    for v in outs[qn]:
        ins[v] -= 1
        last[v] = max(last[v], last[qn] + 1)
        if ins[v] == 0:
            q.append(v)

print(max(last))
