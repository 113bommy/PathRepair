N, x=map(int, input().split())
a=list(map(int, input().split()))
a.sort()
i=0
while i<N and x>=a[i]:
  x-=a[i]
  i+=1
if x>0 and i>0:
  i-=1
print(i)