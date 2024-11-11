n=int(input())
a=[2,1]
for i in range(2,n):
  a.append(a[i-1]+a[i-2])
  
print(a[n-1])