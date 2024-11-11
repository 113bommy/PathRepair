H, W = map(int, input().split())
G = [[ord(s)-96 for s in input().strip()] for _ in range(H)]
G = list(map(list, zip(*G)))
A = [None]*W
B = [None]*W
Col = [None]*W
Dic = [None]*W
for j, Gi in enumerate(G):
    pre = -1
    D = [None]*H
    con = 0
    ctr = 0
    E = [None]*H
    F = []
    for i, g in enumerate(Gi):
        if pre != g:
            F.append(con)
            ctr += 1
            con = 0  
        con += 1
        D[i] = con
        pre = g
        E[i] = ctr
    F.append(con)
    Col[j] = E[:]
    Dic[j] = F[:]
    B[j] = D[:]
    pm = 0
    pre = -1
    for i, (g, d) in enumerate(zip(Gi[::-1], D[::-1])):
        if pre != g:
            pm = 0
        pm = max(pm, d)
        D[H-1-i] = pm
        pre = g
    A[j] = D[:]
C = [[0]*H for _ in range(W)]
for w in range(W):
    for h in range(H):
        c = Col[w][h]
        if c + 2 >= len(Dic[w]):
            continue
        leng = A[w][h] + 1 - B[w][h]
        if Dic[w][c+1] == leng and Dic[w][c+2] >= leng:
            C[w][h] = leng * 10**6 + 900 * G[w][h] + 30 * G[w][h+leng] + G[w][h+leng]
C = list(map(list, zip(*C)))
ans = 0
for Ci in C:
    ctr = 0
    pre = -1
    for c in Ci:
        if not c:
            pre = -1
            continue
        if c != pre:
            ans += ctr * (ctr + 1)//2
            ctr = 1
        else:
            ctr += 1
        pre = c
    ans += ctr * (ctr + 1)//2
print(ans)
