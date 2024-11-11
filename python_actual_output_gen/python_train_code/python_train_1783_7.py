n , m = map(int , input().split())
prices = list(map(int,input().split()))
prices.sort()
tot = 0
for i in prices[:m+1]:
  if i<0:
    tot -= i
print(tot)
