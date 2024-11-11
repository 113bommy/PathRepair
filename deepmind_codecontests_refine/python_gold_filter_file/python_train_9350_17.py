n,k=map(int,input().split())
x=list(map(int,input().split()))
time=100000000000
for i in range(n-k+1):
  l=x[i]
  r=x[i+k-1]
  time=min(time,abs(l)+r-l,abs(r)+r-l)
print(time)
  
      
  
