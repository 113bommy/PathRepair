n=int(input())
ans=0
nmcc=0
i=1
d=[]
while i*i<n:
  if n%i==0:
    d.append(i)
    if i*i!=n:
      d.append(n//i)
  i+=1
for i in d:
  if i==1:
    continue
  tmp=n
  while tmp%i==0:
    tmp//=i
  tmp%=i
  if tmp==1:
    ans+=1

i=1
while i*i<(n-1):
  if (n-1)%i==0:
    nmcc+=1
    if i*i!=n-1:
      nmcc+=1
  i+=1
nmcc-=1
print(ans+nmcc)
  