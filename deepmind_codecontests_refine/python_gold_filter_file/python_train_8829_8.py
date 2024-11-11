n=int(input())
a=list(map(int,input().split()))
b=[]

for i in range(n):
  b.append(a[i]-i)
  
b.sort()

pin=b[n//2]

ans=0

for i in b:
  ans+=abs(pin-i)
  

print(ans)