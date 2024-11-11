import statistics

while True:
  s=int(input())
  if s==0:
    break
  else:
   lst=list(map(int,input().split()))
  print("{0.8}".format(statitics.pstdev(lst)))
  