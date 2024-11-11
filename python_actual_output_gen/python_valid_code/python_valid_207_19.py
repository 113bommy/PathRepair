n = int(input())
result = [i for i in range(1,n+1)]
if n ==1:
  print(-1)
else:
  for i in range(n-1):
    if (i+1)%2 != 0:
      result[i],result[i+1] = result[i+1],result[i]
  for i in result:
    print(i,end="")
    
  