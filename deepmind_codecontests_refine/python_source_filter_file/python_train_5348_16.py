s=input()
f=1
for i in range(len(s)):
    if s[i]=='0':
        s=s[:i]+s[i+1:]
        print(s)
        break
if s.count('0')==0:
    print(s[1:])
