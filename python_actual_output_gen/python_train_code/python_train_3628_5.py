n,k=map(int,input().split())
arr=[i for i in range(1,2*n+1)]
for i in range(k):
  arr[2*i],arr[2*i+1]=arr[2*i+1],arr[i]
print(*arr)

