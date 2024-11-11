a = int(input())
nn = list()
cnt = 0
p = 3
ss = list()
for _ in range(a):
    n = int(input())
    nn.append(n)
for i in range(a):
    if nn[i] == 1:
        ss.append(0)
        continue
    else:
        for j in range(3, nn[i] + 1, 2):
            if j == 3:
                cnt += 8
            else:
                cnt += (j - p) * (2 * j + 2 * (j - 2))
                p += 1
    ss.append(cnt)
    cnt = 0
    p = 0
print(*ss, sep='\n')