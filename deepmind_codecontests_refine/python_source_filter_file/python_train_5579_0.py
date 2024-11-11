ins = map(int, input().split())
n, m = next(ins), next(ins)
cnt = [0] * 20010
cancel = False
for _ in range(m):
    line = list(map(int, input().split()))
    done = False
    for i in range(1, len(line)):
        if line[i] > 0:
            cnt[line[i] + 1000] = 1
            if cnt[line[i]] == 1:
                done = True
                break
        else:
            cnt[abs(line[i])] = 1
            if cnt[abs(line[i]) + 1000] == 1:
                done = True
                break
    if not done:
        cancel = True

    for i in range(1, len(line)):
        cnt[abs(line[i])], cnt[abs(line[i]) + 1000] = 0, 0

if cancel:
    print("YES")
else:
    print("NO")