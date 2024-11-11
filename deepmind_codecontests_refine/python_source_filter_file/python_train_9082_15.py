t = int(input())
for j in range(t):
  l,r,m = [int(x) for x in input().split()]
  for a in range(l,r+1):
    if l+(m % a) < r and m%a>0:
      print(str(a)+' '+str(l+(m % a))+' '+str(l))
      break
    elif l+a-(m % a)<r:
      print(str(a)+' '+str(l)+' '+str(l+a-(m % a)))
      break