s=input()
t=input()
n=len(s)
k=len(t)
c=n
for i in range(n-k+1):
  c1=0
  for j in range(i,i+k):
    if(s[j]!=t[j-i]):
      c1+=1
  c=min(c,c1)
print(c)