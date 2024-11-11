s = input()
c,d,e = 4,0,-1
i = 0
while i<len(s):
    if s[i]=='[':
        break
    i+=1
else:
    print(-1)
    exit(0)
while i<len(s):
    if s[i]==':':
        break
    i+=1
else:
    print(-1)
    exit(0)
i+=1
while i<len(s):
    if s[i]=='|':
        c+=1
    if s[i]==':':
        d=c
    if s[i]==']':
        e=d
    i+=1
print(e)