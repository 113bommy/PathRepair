import bisect
n=int(input())
arr=list(map(int,input().split()))
arr1=[]
for i in range(n):
  arr1.append([arr[i],i])
arr1=sorted(arr1,key= lambda a:a[0])
print(arr1)
q=[-1]*n
k=0
for a in arr1:
  if k<a[1]:
    k=a[1]
  else:
    q[a[1]]=(k-a[1]-1)
print(*q)
