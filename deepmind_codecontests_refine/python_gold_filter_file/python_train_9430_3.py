# haiku
s=str(input())
s1=str(input())
s2=str(input())
s=s.replace(' ','')
s1=s1.replace(' ','')
s2=s2.replace(' ','')
c=0
d=0
e=0
for i in range(0,len(s)):
    if(s[i] in 'aeiou'):
        c=c+1
for i in range(0,len(s1)):
    if(s1[i] in 'aeiou'):
        d=d+1        
for i in range(0,len(s2)):
    if(s2[i] in 'aeiou'):
        e=e+1
if(c==5 and d==7 and e==5):
    print('YES')
else:
    print("NO")