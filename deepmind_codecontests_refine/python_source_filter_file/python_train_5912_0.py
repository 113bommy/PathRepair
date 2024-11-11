N,K,C=map(int,input().split())
S=input()
L=[0 for i in range(K)]
R=[0 for i in range(K)]
n=0
rc=0
lc=0
while True:
  if lc==K:
    break
  if S[n]=="o":
    L[lc]=n+1
    n+=C+1
    lc+=1
  else:
    n+=1
n=N-1
while True:
  if rc==K:
    break
  if S[n]=="o":
    R[N-1-rc]=n+1
    n-=C+1
    rc+=1
  else:
    n-=1
for i in range(K):
  if R[i]==L[i]:
    print(R[i])
