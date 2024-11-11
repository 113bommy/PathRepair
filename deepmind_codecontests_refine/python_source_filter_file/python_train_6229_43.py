A, B = map(int, input().split())
res = []
def make(t, cnt):
    res = []
    for i in range(25):
        res.append([t]*100)
        tmp = [t]*100
        for j in range(50):
            if cnt == 0:
                break
            tmp[2*j] = t^1
            cnt -= 1
        res.append(tmp)
    return res
mp = "WB".__getitem__
ans = make(0, B-1) + make(1, A-1)
print(100, 100)
for l in ans:
    print(*map(mp, l), sep='')