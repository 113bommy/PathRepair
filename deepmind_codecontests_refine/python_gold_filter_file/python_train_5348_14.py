s=input()
f=1
t=s
for i in range(len(s)):
    if s[i]=='0':
        s=s[:i]+s[i+1:]
        print(s)
        break
if t.count('0')==0:
    print(t[1:])
