n = int(input())
l = []
for i in range(n):
    l.append(list(map(int, input().split())))

op = [0 for i in range(n)]
for i in range(n):
    for j in range(i+1, n):
        op[i], op[j] = max(l[i][j], op[i]), max(l[i][j], op[j])
ok = max(op)
s = ""
for i in op:
    if i == ok:
        s += str(ok + 1)
        ok = -1
    else:
        s += str(i)
    s += " "
print(s)
