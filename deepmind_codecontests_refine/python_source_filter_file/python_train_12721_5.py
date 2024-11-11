for _ in[0]*int(input()):
 n=int(input());s='';i=j=0
 while n:s=str(n%3)+s;n/=3
 s='0'+s;i=s.find('2');r=0
 if i+1:k=s.rfind('0',0,i);s=s[:k]+'1'+'0'*(len(s)-k-1)
 for c in s:r=r*3+int(c)
 print(r)