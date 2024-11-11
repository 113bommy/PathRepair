from  fractions import gcd
N=int(input())
A=list(map(int,input().split()))
L=[0]
R=[0]
ans=1
for i in range(N-1):
    R.append(gcd(R[-1], A[::-1][i]))
    L.append(gcd(L[-1], A[i]))
print(max(gcd(l,r)for l,r in zip(L,R[::-1])))