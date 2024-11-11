a=[]
while 1:
 n=input()
 if n=='0 0':break
 a.append(n)
for s in a:
 x=sorted(map(int,s.split()))
 print(*s)