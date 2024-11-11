N=int(input())
C=0
 
for i in range(1,N+1):
  if len(str(i))%2!=0:
    C+=1
    
print(C)