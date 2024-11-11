S=input()
N=len(S)
L=[0]*(N+1)
for i in range(len(S)):
    if S[i]=="<":
        L[i+1]+=L[i]+1

for i in range(len(S)-1,-1,-1):
    if S[i]==">":
        L[i]=max(L[i+1]+1,L[i])
print(L)
print(sum(L))