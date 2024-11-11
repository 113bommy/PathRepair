n=int(input())
a=list(map(int,input().split()))
sum = 0
min_odd = 10001
for x in a:
  if(x > 0):
    sum += x
  if(x % 2 != 0):
    min_odd = min(abs(x),min_odd)
if(sum % 2 != 1):
  sum -= min_odd
print(sum)