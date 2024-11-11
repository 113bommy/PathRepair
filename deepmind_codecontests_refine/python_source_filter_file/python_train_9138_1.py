N = int(input())
S = []
for i in range(N):
    S.append(input())
    

#二部グラフ判定
L = [0 for i in range(N)]
L[0] = 1
q = [0]
res = 0

while len(q) > 0:
    idx = q.pop(-1)
    c = L[idx]*(-1)
    for i in range(N):
        if S[idx][i] == "1":
            if L[i] == 0:
                L[i] = c
                q.append(i)
            elif L[i] == c*(-1):
                res = 1
                q.clear()
                break
            

if res == 1:
    print(-1)
else:
    # Warshall-Floyd法で直径を求める
    d = [[10**4 for j in range(N)] for i in range(N)]
    # initialize
    for i in range(N):
        for j in range(N):
            if S[i][j] == "1":
                d[i][j] = 1
    
    # DP
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if i != j:
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j])

                
    ans = 0
    for i in range(N):
        for j in range(N):
            if d[i][j] < 10**4:
                ans = max(ans, d[i][j])
                
    print(ans+1)