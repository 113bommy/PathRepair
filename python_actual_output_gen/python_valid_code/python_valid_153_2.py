N=int(input())
S=input()
a,i,j=0
while j<N:
  t=S[i:j]
  if t in S[j:]:
    a=max(a,len(t))
    j+=1
  else:
    i+=1
print(a)