for e in iter(input,'0'):
while 1:
 b,c=1000-int(e),0
 for i in[500,100,50,10,5]:
  d,b=divmod(b,i)
  c+=d
 print(b+c)
