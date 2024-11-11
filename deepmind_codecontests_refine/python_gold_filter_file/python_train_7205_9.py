for _ in range(int(input())):
  coin=[int(i)for i in input().split()]
  n=coin.pop();coin.sort()
  count=0
  for i in range(2):
    count+=coin[len(coin)-1]-coin[i]    
  n=n-count
  if n>=0:
    if n%3==0:
      print("YES")
    else:
      print("NO")  
  else:
    print("NO")    
