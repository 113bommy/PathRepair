a=[]
while True:
 n=input()
 if n.find('?')>0:break
 a.append(n)
for s in a:
 t=s.split()
 if t[1]=='/':
  print(int(t[0])//int(t[2]))
 else:
  print(eval(''.join(t)))