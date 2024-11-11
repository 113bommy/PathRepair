s=input()
alp='abcdefghijklmnopqrstuvwxyz'
for a in alp:
    if a in s:
        s=s.replace(a,'')
f=s.find('[')
b=s.rfind(']')
if f==-1 or b==-1 or f>b:
    print(-1)
    exit()
f1=s[f:].find(':')
b1=s[:b].rfind(':')
if f1==-1 or f+f1>=b1:
    print(-1)
    exit()
l=0
for i in range(f+f1,b1):
    if s[i]=='|':
        l+=1
print(4+l)
