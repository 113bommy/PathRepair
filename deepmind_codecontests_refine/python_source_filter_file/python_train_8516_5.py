N = int(input())
S = input()
Q = int(input())
*K, = map(int,input().split())

"""
nD = S.count("D")
nC = S.count("C")
if nD < nC:
    S = S[::-1].replace("D","c").replace("C","d").upper()
"""

D = [0]*(N+1)
cntM = [0]*(N+1)
sumM = [0]*(N+1)
ans = [0]*Q
for i,s in enumerate(S):
    D[i+1] = D[i]
    cntM[i+1] = cntM[i]
    sumM[i+1] = sumM[i]
    if s=="D":
        D[i+1] += 1
    elif s=="M":
        cntM[i+1] += 1
        sumM[i+1] += D[i]
    elif s=="C":
        for j,k in enumerate(K):
            ik = max(0,i-k+1)
            d = D[ik]
            ans[j] += (sumM[i]-sumM[ik]) - d*(cntM[i]-cntM[ik])
for out in ans:
    print(out)