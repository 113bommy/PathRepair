l=input()
s=input('')
t=''
ct = 0
kek=len(s)
if kek==1 and s[0]!=1:
  t='0'
else:
  ct=s.count('0')
  t='1'+ '0'*ct  
print (t)
