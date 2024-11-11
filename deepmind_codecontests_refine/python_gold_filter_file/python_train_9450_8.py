n,k=map(int,input().split())
a=list(map(int,input().split()))
result=[1]
temp=1
for i in range(n):
  temp=a[temp-1]
  result.append(temp)
temp=result.index(result[len(result)-1])
c=len(result)-temp-1
if k<n:
  print(result[k])
else:
  print(result[temp+(k-temp)%c])