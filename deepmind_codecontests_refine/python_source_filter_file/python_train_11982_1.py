s=input()
z=''
t=''
o=''
f=0
for i in range(len(s)):
    if s[i]=='0':
        t+='0'
    elif s[i]=='2':
        t+='2'
    else:
        o+='1'
for i in range(len(t)-1):
    if t[i]=='2':
        t=t[:i]+o+t[i:]
        f=1
        break
if f==0:
    t=t+o
print(t)