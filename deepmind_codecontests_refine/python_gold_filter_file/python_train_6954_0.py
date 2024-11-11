from itertools import groupby
 
[H, W] = map(int, input().split())
Ss = [list(map( lambda x: int(x == "."), list(input()) )) for _ in range(H)]
 
res = 0
count = [[-Ss[i][j] for j in range(W)] for i in range(H)]
for i in range(H):
    j = 0
    for x in groupby(Ss[i]):
        k = len(list(x[1]))
        for _ in range(k):
            count[i][j] += k * x[0]
            j += 1

for j in range(W):
    i = 0
    for x in groupby([Ss[i][j] for i in range(H)]):
        k = len(list(x[1]))
        for _ in range(k):
            new_res = count[i][j] + k * x[0]
            if res < new_res:
                res = new_res
            i += 1

print(res)
