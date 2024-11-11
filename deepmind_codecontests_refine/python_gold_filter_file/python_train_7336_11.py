s = list(input())
t = list(input())
i=len(s)-1
while i>=0:
    if s[i]!='z':
        s[i]=chr(ord(s[i])+1)
        break
    else:
        s[i]='a'
    i-=1
if t>s:print(''.join(s))
else:print('No such string')