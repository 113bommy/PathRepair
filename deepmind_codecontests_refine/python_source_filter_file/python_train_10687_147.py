n,k=list(map(int,input().split()))
i=1
while i <= k:	
 if n%10!=0:
  n=n-1
  i=i+1
 else:
  n/=10
  i+=1
print(n)
 
 