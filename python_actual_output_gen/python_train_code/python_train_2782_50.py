N=int(input())
C=0

for i in range(N):
  if len(str(i))%2!=0:
    C+=1
    
print(C)