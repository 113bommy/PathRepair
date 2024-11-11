n=int(input())
if n%2:
   print(0)
   exit()

n//=2
ans=0
i=1
while n>(5**i):
   ans+=n//(5**i)
   i+=1
print(ans)