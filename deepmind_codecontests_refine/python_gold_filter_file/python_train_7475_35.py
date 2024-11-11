n,q=list(map(int,input().split()))
s=input()
li=[0]
c=0
for i in range(1,n):
  if s[i-1]=="A" and s[i]=="C":
    c+=1
  li.append(c)

for i in range(q):
  l,r=list(map(int,input().split()))
  l-=1
  r-=1
  print(li[r]-li[l])