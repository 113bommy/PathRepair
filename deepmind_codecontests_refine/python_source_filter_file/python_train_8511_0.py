N = int(input())
pf={}
m=2*N
for i in range(2,int(m**0.5)+1):
    while m%i==0:
        pf[i]=pf.get(i,0)+1
        m//=i
if m>1:pf[m]=1

pL = list(pf.keys())
NpL = len(pL)
import itertools
Ls = list(itertools.product([0,1], repeat=NpL))

out = N
for i in range(len(Ls)):
    L = Ls[i]
    X = 1
    Y = 1
    for j in range(NpL):
        if L[j]==1:
            X *= pL[j]**pf[pL[j]]
        else:
            Y *= pL[j]**pf[pL[j]]

    R = [X,Y]            # 降順
    R.sort(); R.reverse()   # 念の為
    Q = [0]
    a,b = R[0],R[1]
    while b!=0:
        Q.append(a//b)
        R.append(a%b)
        a,b = b, a%b

    q = list(reversed(Q))
    n = len(Q)
    c = [0,1]+[0]*(n-2)
    for i in range(2,n):
        c[i] = q[i-1]*c[i-1]+c[i-2]
    C = list(reversed(c))
    if C[0]>=1 and C[1]>=1:
        cand1 = C[0]*X
        cand2 = C[0]*X-1
        if (cand1*(cand1+1))%(2*N)==0:
            out = min(out,cand2)
        if (cand2*(cand2+1))%(2*N)==0:
            out = min(out,cand2)

print(out)