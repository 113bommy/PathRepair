import sys
t='X'
for e in sys.stdin:
 for i in'0123456789'[(e[0]==t)*(e[1]!='+')or('+X'in e)*('+X='not in e)or(1 and'=X'in e):]:
  l,r=e.replace(t,i).split('=')
  if sum(map(int,l.split('+')))==int(r):print(i);break
 else:print('NA')
