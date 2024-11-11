N=int(input())
S=input()
ct=0
for i in range(N-1):
  if S[i]!=S[i+1]:
    ct+=1
print(ct)