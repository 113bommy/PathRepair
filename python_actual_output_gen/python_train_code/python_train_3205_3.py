s=input()
if s[:2]=='at':
    z=2+s[2:].index('at')
else:
    z=s.index('at')
s=s[:z]+'@'+s[z+2:]

if s[:3]=='dot':
    pr='dot'
    s=s[3:]
else:
    pr=""
if s[:-3]=='dot':
    po='dot'
    s=s[:-3]
else:
    po=""
s=s.replace("dot",'.')
print(pr+s+po)
