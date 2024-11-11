def getLPS(s2,l):
  lps=[0]*l
  i=1
  j=0
  while i<l:
    if s2[i]==s2[j]:
       lps[i]=j+1 
       j+=1
       i+=1
       
    else:
      if j!=0:j=lps[j-1]
      else:
       lps[i]=0
       i+=1
  return lps
s=input()
n=len(s)
p=getLPS(s,n)
#print(p)
ans=[]
f=[0]*n
for i in range(n):
  f[p[i]]+=1
#print(f)
for i in range(n-1,0,-1):
  f[p[i-1]]+=f[i]
#print(f)
pos=n-1
ans=[[n,1]]
while pos>0:
  #print(pos)
  if p[pos]>1:
    ans.append([p[pos],f[p[pos]]+1])
  pos=p[pos]-1
 
if len(s)>1:
  f=s.count(s[0])
  if s[0]==s[len(s)-1]:
    ans.append([1,f])
print(len(ans))
for i in sorted(ans):
  print(i[0],i[1])
