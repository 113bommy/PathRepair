n=int(input())
arr1=[]
arr2=[]
for _ in range(n):
  a,b=map(int,input().split())
  arr1.append(a)
  arr2.append(b)
arr1=sorted(arr1)
arr2=sorted(arr2)
if n%2==1:
  l=arr1[n//2]
  r=arr2[n//2]
else:
  l=arr1[n//2]+arr1[n//2+1]
  r=arr2[n//2]+arr2[n//2+1]
print(r-l+1)