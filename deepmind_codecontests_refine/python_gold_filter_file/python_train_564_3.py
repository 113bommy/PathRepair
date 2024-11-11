d={chr(ord('a')+i):0 for i in range(26)}
d2={chr(ord('a')+i):0 for i in range(26)}
s=input()
t=input()
for ch in s:
    d[ch]+=1
for ch in t:
    d2[ch]+=1
fl1=fl2=False
for ch in d.keys():
    if d[ch]>d2[ch]:
        fl1=True
    if d[ch]<d2[ch]:
        fl2=True
if (not fl1)and(not fl2):
    print('array')
elif fl2:
    print('need tree')
else:
    i1=0
    i2=0
    for i1 in range(len(s)):
        if(i2==len(t)):
           break
        if(s[i1]==t[i2]):
            i2+=1
    if(i2==len(t)):
        print('automaton')
    else:
        print('both')