k,s=map(int,input().split())

i=0

for l in range(k+1):
  for m in range(k+1):
    if 0<s-l-m<=k:
      i+=1
      
print(i)