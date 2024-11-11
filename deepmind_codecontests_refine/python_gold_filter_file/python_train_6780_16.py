import re

s = input()
k = int(input())

a = s.count('*')
b = s.count('?')
k-=len(s)-(a+b)*2
if k<0 or a==0 and k>b:
    print('Impossible')
else:
    if a==0:
        c=b-k
    else:
        c=b
    if c!=0:
        s=re.sub(r'.\?','',s,count=c)
    s,q=re.subn(r'(.)\?',r'\1',s)
    k-=q

    if k>0:
        s=re.sub(r'(.)\*',r'\1'*k,s,count=1)
    s=re.sub(r'.\*','',s)
    print(s)
