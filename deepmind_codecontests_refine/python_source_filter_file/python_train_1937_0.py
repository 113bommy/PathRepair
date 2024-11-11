a=int(input())
b=input()
b=b.split(' ')
s=[]
for i in range(len(b)):
    b[i]=int(b[i])
    s.append(b[i])
s.sort()
f1=b.count(s[0])
b.remove(s[0])
f2=b.count(s[1])
b.remove(s[1])
f3=b.count(s[2])
b.remove(s[2])
f4=f1*f2*f3
if s[1]==s[2] and s[2]==s[3]:
    f4=f4//6
if s[1]==s[2] and s[2]!=s[3]:
    f4=f4//2
if s[1]==s[3] and s[3]!=s[2]:
    f4=f4/2
if s[2]==s[3] and s[1]!=s[2]:
    f4=f4/2
print(f4)

