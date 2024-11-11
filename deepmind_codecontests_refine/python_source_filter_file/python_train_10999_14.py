n=int(input())
lst=[]
for i in range(n):
  a=list(map(int,input().split()))
  lst.append(a)
l=[]
r=[]
llst = list(lst)
lst.sort()
for i in range(1,n):
  if lst[i][0] > lst[i-1][0]:
    if lst[i][1] <= lst[i-1][1]:
      l=lst[i]
      r=lst[i-1]
      break
  if lst[i][0] == lst[i-1][0]:
    if lst[i][1] <= lst[i-1][1]:
      l=lst[i]
      r=lst[i-1]
      break
    else:
      l=lst[i-1]
      r=lst[i]
      break
lind=-1
rind=-1
f=0
ff=0
for i in range(n):
  if lst[i] == l and f==0:
    lind=i+1
    f=1
  elif lst[i] == r and ff==0:
    rind = i+1
    ff=1
print(lind,rind)