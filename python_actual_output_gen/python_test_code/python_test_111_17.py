n=int(input())
h=list(map(int,input().split()))
a=b=1
for i in range(n-1):
  if h[i]>=h[i+1]:b+=1
  else:b=1
  a=max(a,b)
print(a)