
s=input()
s=s.lower()
l=list(s)
m=[]
for i in range(len(l)):
    if l[i] not in 'aeiou':
        m.append(l[i])
final=""
for i in range(len(m)):
    final=final+'.'+m[i]
print(final)