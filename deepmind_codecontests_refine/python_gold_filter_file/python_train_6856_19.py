N=int(input())
k=1

for i in range(1,N+1):
  if i*(i+1)//2 >= N:
    k=i
    break
    
c = int(k*(k+1)//2 - N)

for j in range(1,k+1):
  if j!=c:
    print(j)