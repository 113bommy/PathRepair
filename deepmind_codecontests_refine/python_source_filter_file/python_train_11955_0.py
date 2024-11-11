import sys
input = sys.stdin.readline
n,m = map(int,input().split())
A = list(map(int,input().split()))
C = [list(map(int,input().split())) for i in range(m)]

V = [0] * (n)
# P = [-1] * (n+1)

M = [[] for i in range(n)]
for i in range(m):
    M[C[i][0]].append(C[i][1])
    M[C[i][1]].append(C[i][0])

# 1始まりの場合
BB = []
one = 0
for ii in range(n):
    B = []
    if V[ii] == 0:
        Q = [ii]
        s = 0
        V[ii] = 1
        onef = 1
        B.append([ii,A[ii]])
        while s < len(Q):
            i = Q[s]
            for x in M[i]:
                if V[x] == 0:
                    V[x] = 1
                    onef = 0
                    B.append([x,A[x]])
                    # P[x] = i
                    Q.append(x)
            s += 1
        if onef == 1:
            one += 1
        B.sort(key=lambda x:x[1])
        BB.append(B[0])

if len(BB) == 1:
    print(0)
elif len(BB)*2 > n:
    print("Impossible")
else:
    ans = sum([i[1] for i in BB])
    # print(ans)
    anoBind = [0] * n
    anoB = []
    for i in range(len(BB)):
        anoBind[BB[i][0]] = 1
    for i in range(n):
        if anoBind[i] == 0:
            anoB.append(A[i])
    anoB.sort()
    # print(anoB)
    ans += sum(anoB[:len(BB)-2])
    print(ans)