n, A=map(int, input().split())
C=list(map(int, input().split()))
T={}
CB=-1
CA=0
for i in range(n):
    if C[i]==A:
        CA+=1
    elif C[i] in T:
        if C[i]>=CA:
            T[C[i]]+=1
        else:
            T.pop(C[i])
    elif CA==0:
        T[C[i]]=1
for i in T:
    if T[i]>=CA:
        CB=i
        break
print(CB)