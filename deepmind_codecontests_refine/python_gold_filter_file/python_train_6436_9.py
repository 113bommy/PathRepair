N,M = map(int,input().split())
xyz = [list(map(int,input().split())) for _ in range(N)]

ans = 0
for n in range(8):
    n = bin(n)[2:]
    n = (3-len(n))*'0' + n
    n = [1-2*int(s) for s in n]
    S = [0]*N
    for i in range(N):
        S[i] = n[0]*xyz[i][0]+n[1]*xyz[i][1]+n[2]*xyz[i][2]
    S.sort()
    ans = max(ans,sum(S[N-M:]))

print(ans)