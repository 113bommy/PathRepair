n,k=map(int,input().split())
h=0
for i in range(1,n+1):
  j=0
  while i<k:
    i*=2
    j+=1
  h+=1/(n*2**j)
  
print(h)