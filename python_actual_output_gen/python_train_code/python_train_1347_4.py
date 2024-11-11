def lucky(n):
  
  ans = 0
  i = 0
  while(n>0):
    temp = n%10
    temp = 1 if temp==4 else 2
    ans += (temp*(1<<i))
    n = int(n/10)
    i+=1

  return ans+1
  
n = int(input())
print(lucky(n))