n=int(input())
d=list(map(int,input().split()))
s=0
for i in range(n-1):
  for j in range(i+1,n):
    s+=i*j
print(s)