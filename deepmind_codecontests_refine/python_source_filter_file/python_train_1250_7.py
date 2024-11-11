def partition(n,a,p,r):
  x = a[r]
  i = p - 1
  
  for j in range(p,r):
    if x >= a[j]:
      i += 1
      a[i],a[j] = a[j],a[i]
      
  a[i+1],a[r] = a[r],a[i+1]
  
  for k in range(i+1):
    print(a[k],end=" ")
    
  print("[{}]".format(x),end=" ")
  
  for k in range(i+2,r+1):
    print(a[k],end=" ")
    
  print()

n = int(input())
a = list(map(int,input().split()))
partition(n,a,0,len(a)-1)