n=int(input())
a=list(map(int,input().split()))
b=[0 for _ in range(n)]
for i in range(n):
  b[a[i]-1] = i+1
print(b)