mx = 0
s = list(map(int, input().split()))
for i in range(14):
 if s[i]>0:
  res = 0
  sw = list(s)
  x = sw[i]
  sw[i]=0
  if x<14-i-1:
   for j in range(i+1, i+x+1):
    sw[j]+=1
  else:
   x-=14-i-1
   for j in range(i+1, 14):
    sw[j]+=1
   t = x//14
   ost = x%14
   for j in range(14):
    if j<ost:
     sw[j]+=t*14+1
    else:
     sw[j]+=t*14
  for x in sw:
   if x%2==0:
    res+=x
  if res>mx:
   mx = res

print(mx)