a=input()
a=a.replace('WEB',' ')
a=a.split(' ')
s=''
for i in a:
    if not i=='':
        s=s+' '+i
s=s.lstrip(' ')
s=s.lstrip(' ')
print(str(s))