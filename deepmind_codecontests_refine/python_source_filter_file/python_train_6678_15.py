from collections import Counter
n=int(input())
arr=list(map(int,input().split()))
#
d={}
for i in arr:
  d[i]=d.get(i,0)+1
d=sorted(d.items(),key=lambda x:x[0])
e=d[-1][0];minn=-1
for i in range(n):
  if arr[i]==e:minn=i;break
#
#print(minn,e)
ans=[];flag=False
for i in range(minn,n):
  if i+1<n and arr[i+1]>e:ans.append([2,i+2,i+1])
  if i+1<n and arr[i+1]<e:ans.append([1,i+2,i+1])
for  j in range(minn,-1,-1):
 if j-1>=0 and arr[j-1]>e:ans.append([2,j,j+1])
 elif j-1>=0 and arr[j-1]<e:ans.append([1,j,j+1])
print(e)
for i in ans:print(*i)
