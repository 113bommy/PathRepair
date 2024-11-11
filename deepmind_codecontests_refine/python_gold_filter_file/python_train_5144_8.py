n , m = map(int , input().split())
prices = list(map(int,input().split()))
prices.sort()
tot = 0
for i in prices[:m]:
  if i<0:
    tot -= i
print(tot)

