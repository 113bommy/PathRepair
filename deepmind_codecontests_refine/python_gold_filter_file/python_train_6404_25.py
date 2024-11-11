s1=input()
s2=input()
a=[]
for i in range(len(s1)):
    if s1[i]==s2[i]:
        a.append('0')
    else:
        a.append('1')
print(''.join(x for x in a))