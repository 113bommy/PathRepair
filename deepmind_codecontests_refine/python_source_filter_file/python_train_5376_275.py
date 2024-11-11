n=int(input())
m=int(input())
stepen=2
k=1
while (stepen<m) and (k<n):
   stepen*=2
   k+=1   
print(int(m % stepen))    
