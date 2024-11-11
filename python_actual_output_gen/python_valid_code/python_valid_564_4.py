t = int(input())
while t:
  t-=1
  s = int(input())
  n = list(map(int,input()))
  print(sum(n) + len(n)-n.count(min(n)) - (n[-1]!=0))