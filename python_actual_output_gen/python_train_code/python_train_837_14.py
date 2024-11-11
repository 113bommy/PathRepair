N=int(input())
S=input()
s=0
s+=S.count('R')*S.count('G')*S.count('B')
for i in range(N):
  for j in range(i+1,j):
    k=2*j-1
    if k<n and S[i]!=S[j] and S[j]!=S[k] and S[k]!=S[i]:
      s-=1
print(s)      