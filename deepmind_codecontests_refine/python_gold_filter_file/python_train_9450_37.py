n,k=map(int,input().split())
arr=list(map(int,input().split()))
for i in range(n):
  arr[i]-=1
flag=format(k,'b')
flag=flag[::-1]
pos=0
for i in range(len(flag)):
  if flag[i]=='1':
    pos=arr[pos]
  tmp=[]
  for j in range(n):
    tmp.append(arr[arr[j]])
  arr=tmp
print(pos+1)