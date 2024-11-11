import sys
b=0
a=[{},{}]
for e in sys.stdin:
 if'\n'==e:b=1
 else:
  c=int(e.split(',')[0])
  if c in a[b]:a[b][c]+=1
  else:a[b][c]=1
for k in sorted({*a[0]}&{*a[1]}):print(k,a[0][k]+a[1][k])
