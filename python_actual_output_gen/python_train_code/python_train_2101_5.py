n = int(input())
t = input().split()
t[0] = t[0].lower()
t[2] = t[2].lower()
m = [[t[0], t[2], 2]]
for i in range(1, n):
    t = input().split()
    t[0] = t[0].lower()
    t[2] = t[2].lower()
    m.append([t[0], t[2], 0])
    for k in range(len(m)):
        if m[i][1] == m[k][0]:
            m[i][2] = m[k][2] + 1
u = []
for i in range(len(m)):
    u.append(m[i][2])
a = max(u)
print(a)
