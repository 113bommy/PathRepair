s = input()

n = len(s)+1
L = [0]*(n)

for i in range(n-1):
  if s[i]=='<':
    L[i+1] = max(L[i+1],L[i]+1)

for i in range(n-2,-1,-1):
  if s[i]=='>':
    L[i] = max(L[i],L[i+1]+1)
    
print(sum(L))    