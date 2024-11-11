n=int(input())
l=int(input())
arr=[int(input()) for _ in range(n)]
arr=sorted(arr, reverse=True)
tmp=0
ans=0
for i in range(n):
  tmp+=arr[i]
  if tmp>=l:
    ans=i
    break
print(ans)
    