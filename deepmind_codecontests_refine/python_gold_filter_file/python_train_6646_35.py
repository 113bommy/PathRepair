N,M=map(int,input().split())
A=[[int(i) for i in input().split()] for _ in range(N)]
R=[0 for i in range(M)]
for i in range(N):
    R[A[i][0]-1]+=1
P=0
Q=0
S=set()
for i in range(N):
    if R[A[i][0]-1]>=P:
        P=R[A[i][0]-1]
        Q=A[i][0]
S.add(Q)
while(len(S)<M):
    Pd=0
    Qd=0
    R=[0 for i in range(M)]
    for i in range(N):
        for j in range(M):
            if not(set([A[i][j]]) <= S):
                R[A[i][j]-1]+=1
                break
    for j in range(M):
        if R[j]>=Pd:
            Pd=R[j]
            Qd=j+1
    if Pd<P:
        P=Pd
    S.add(Qd)
print(P)
