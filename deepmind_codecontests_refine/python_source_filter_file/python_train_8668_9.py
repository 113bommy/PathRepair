def check(s,c,t):
  sums = (c*t)+(t-1)
  count = int((sums)/(s-1))
  r =((sums)%(s-1))
  if(r!=0):
    count+=1
  count = count+t 
  count = int(count)
  print(count)  

for _ in range(int(input())):
  s,c,t = map(int,input().split())
  check(s,c,t)