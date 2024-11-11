N=int(input())
A=list(map(int, input().split()))
arr=[None]*N
for a in range(N):
  arr[A[a]-1]=a+1
print(*arr)
