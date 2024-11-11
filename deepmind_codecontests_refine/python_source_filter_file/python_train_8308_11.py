n=int(input())
l=[]
for i in range(n):
  l.append(int(input()))
d={}
for i in range(n):
  d[l[i]]=i+1
ans=0
ans1=1
index=1
while index<n:
  index+=1
  if d[index]>d[index-1]:
    ans1+=1
  else:
    if ans<ans1:
      ans=ans1
      ans1=1
if ans<ans1:
  ans=ans1
print(n-ans)