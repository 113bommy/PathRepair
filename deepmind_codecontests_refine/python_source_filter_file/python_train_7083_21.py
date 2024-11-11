while 1:
 a=input()
 if a.isdigit():
  if c>0:c+=int(a)
  else:c=1
 else:
  if c!=0:print((s*2)[c%l-1:][:l])
  if'-'==a:break
  s=a;l=len(s);c=0