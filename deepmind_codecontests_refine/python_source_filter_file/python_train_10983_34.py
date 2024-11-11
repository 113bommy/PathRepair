s = input()
a, b = 0, 0
for i in range(len(s)):
    if s[i]>='a' and s[i]<='z':
        a+=1
    elif s[i]>'A' and s[i]<='Z':
        b+=1

print(s.lower() if a>=b else s.upper())