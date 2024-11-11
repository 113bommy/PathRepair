n = int(input())
s = input()
r = input()
l=0
z=0
for i in range(len(s)):
    if(s[i]=='1' and r[i]=='0'):
        l+=1
    if(s[i]=='0' and r[i]=='0'):
        z+=1
print(z*s.count('1')+(s.count('0')-z)*l)
