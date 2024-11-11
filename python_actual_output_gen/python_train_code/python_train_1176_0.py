k=int(input())
n=0
for i in range(1,k):
  n=n*10+7
  n=n%k
  if n==0:
    print(i)
    break
print(-1)
    
  