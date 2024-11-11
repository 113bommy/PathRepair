input()
x=list(map(int, input().split()))
nc = [a for a in x if a%2==1]
if len(nc) == 0:
  print(0)
  exit(0)
print(sum(x)-min(nc)*(len(nc)%2))