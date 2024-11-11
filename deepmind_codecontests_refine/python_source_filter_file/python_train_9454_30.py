N = int(input())

for k in range(N + 1):
    sn = k - 1
    if k * sn != 2 * N:
        continue

    print("Yes")
    print(k)
    s = [[0] * sn for _ in range(sn)]
    for i in range(sn):
        s[i][i] = s[i-1][i-1] + (i + 1)
        for j in range(i + 1, sn):
            s[i][j] = s[i][j-1] + j
            s[j][i] = s[i][j]
    s.append([s[i][i] for i in range(sn)])
    for x in s:
        print(sn, " ".join(map(str, x)))
    break
else:
    print("No")