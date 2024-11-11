s=input()
t=input()
n=len(s);k=len(t)
an=k
for i in range(n-k+1):
  a=s[i:i+k]
  ct=0
  for j in range(k):
    if a[j]!=t[j]:
      ct+=1
  an=min(an,ct)
print(an)