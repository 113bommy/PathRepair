import math
N=int(input())
q=int(math.sqrt(N*2))
if-~q*q+q<N:print("No");exit()
S=[list(range(1,q+1))]
S+=[[j]for j in S[0]]
l=q
for i in range(1,q):
	r=list(range(l+1,l+1+q-i))
	S[i]+=r
	for j in range(q-i):S[i+j+1]+=[r[j]]
	l=r[-1]
print("Yes")
print(len(S))
for s in S:print(len(s)," ".join(map(str,s)))