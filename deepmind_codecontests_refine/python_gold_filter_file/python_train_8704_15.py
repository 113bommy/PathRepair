s=input()
l=len(s)
for i in range(0,l):
    if s[i]!='0':
        s=s[i:]
        break
l=len(s)
for i in range(1,l+1):
    if s[l-i]!='0':
        s=s[:l-i+1]
        break
l=len(s)
f=0
for i in range(0,int(l/2)):
    if(s[i]!=s[l-i-1]):
        f=1
        break
if f==0:
    print("YES")
else:
    print("NO")