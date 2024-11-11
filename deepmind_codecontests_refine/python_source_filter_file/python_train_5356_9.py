p,n=map(int,input().split())
d={}
for i in range(p):
  d.update({i:[]})
index,flag=-1,True
for i in range(n):
  a=int(input())
  a=a%10
  d[a].append(1)
  if len(d[a])>1 and flag==True:
    flag=False
    index=i+1
print(index)
