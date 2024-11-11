N=int(input())

for i in range(1,N):
  if i*(i+1)//2 >= N:
    i=k
    break
    
c = int(k*(k+1)//2 - N)

for j in range(1,k+1):
  if j!=c:
    print(j)