from itertools import accumulate

H, W, K = map(int, input().split())
s = [input() for _ in range(H)]

ans = []
acc = 0
l = 0
for i in s:
    cnt = i.count("#")
    if cnt == 0:
        if not ans:
            l += 1
        else:
            ans.append(ans[-1])
    else:
        k = [0] * W
        for j in range(W):
            if i[j] == "#":
                k[j] = 1
        k = list(accumulate(k))
        for j in range(W):
            if k[j] == 0:
                k[j] = 1
            k[j] += acc
        ans.append(k)
    if ans and l >= 1 :
        for _ in range(l):
            ans.append(ans[-1])
        l = 0
    acc += cnt
        
for i in ans:
    print(" ".join(map(str, i)))