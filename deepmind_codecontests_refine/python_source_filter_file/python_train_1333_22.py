q = -1
r = 9
for i in range(5):
  k = int(input())
  q += (k-1)//10+1
  r = min(r-1,(k-1)%10)+1
print(q*10+r)