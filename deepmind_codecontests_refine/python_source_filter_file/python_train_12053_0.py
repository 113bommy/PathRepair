N = int(input())
A = list(map(int,input().split()))
INF = 2*N
DP = [[-INF]*(N+1) for _ in range(N+1)]
M = 0
rowM = [-INF]*(N+1)

def chmax(i,j,k):
    DP[i][j] = max(k,DP[i][j])
    DP[j][i] = max(k,DP[j][i])
    rowM[i] = max(rowM[i],DP[i][j])
    rowM[j] = max(rowM[j],DP[i][j])
    global M
    M = max(M,k)

ans = 0
DP[A[0]][A[1]] = 0
DP[A[1]][A[0]] = 0
rowM[A[0]] = 0
rowM[A[1]] = 0
for i in range(N-1):
    new = A[3*i+2:3*i+5]
    change = []
    if len(set(new)) == 1:
        ans += 1
        continue
    if len(set(new)) == 2:
        for j in range(3):
            if new.count(new[j]) == 2:
                X = new[j]
            else:
                Y = new[j]
        for j in range(1,N+1):
            change.append((j,Y,DP[X][j]+1))
    X,Y,Z = new
    change.append((X,Y,DP[Z][Z]+1))
    change.append((Y,Z,DP[X][X]+1))
    change.append((X,Z,DP[Y][Y]+1))
    change.append((X,Y,M))
    change.append((X,Z,M))
    change.append((Y,Z,M))
    for j in range(1,N+1):
        for k in range(3):
            change.append((j,A[k],rowM[j]))
    for j,k,l in change:
        chmax(j,k,l)
M = max(M,DP[A[-1]][A[-1]]+1)
print(ans+M)