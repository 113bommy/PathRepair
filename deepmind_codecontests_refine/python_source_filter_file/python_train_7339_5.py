l=[]
s=''
f=[]
for i in range(8):
  l.append(input())
for i in range(8):
  s=''
  for j in range(8):
    s=s+l[j][i]
  f.append(s)
minw=999
minb=-999
cw=999
cb=999
for i in range(8):
  if 'W' in f[i] and 'B' in f[i]:
    a=f[i].index('W')
    b=f[i].index('B')
    f[i]=f[i][::-1]
    c=f[i].index('W')
    d=f[i].index('B')
    c=7-c
    d=7-d
    if a<b and minw>a:
      minw=a
    if d>c and minb<d:
      minb=d
  elif 'W' in f[i]:
    if minw>7-f[i].index('W'):
      minw=f[i].index('W')
  elif 'B' in f[i]:
    f[i]=f[i][::-1]
    if minb<7-f[i].index('B'):
      minb=7-f[i].index('B')
if minw==7-minb:
  print('A')
elif minw<7-minb:
  print('A')
else:
  print('B')

    
      
