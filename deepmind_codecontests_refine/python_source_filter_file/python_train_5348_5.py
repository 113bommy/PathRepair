s=input()
f=0
for i in range(len(s)):
    if s[i]=='0':
        a=s[:i]+s[i+1:]
        f=1
        break
if f:
    print(a)
else:
    print(s)