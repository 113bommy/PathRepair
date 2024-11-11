import sys
for e in sys.stdin:
 a='';b=n=0
 for c in e[:-1]:
  if'@'==c:b=1
  elif b&1:n=int(c);b=2
  elif b&2:a+=c*n;b=0
  else:a+=c
 print(a)
