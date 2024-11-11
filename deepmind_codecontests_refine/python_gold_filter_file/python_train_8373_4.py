s1=input()
s2=input()

b=list(set(s2))
if ' ' in b:
    b.remove(' ')

c=0
for i in b:
    if s2.count(i)<=s1.count(i):
        c+=1

if c==len(b):
    print('YES')
else:
    print('NO')
