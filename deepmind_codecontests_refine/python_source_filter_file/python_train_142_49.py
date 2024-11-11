s=input()
b=[]
c=['1','2','3']
for i in s:
    if i in c:
        m=int(i)
        b.append(m)

b.sort()
p=b.pop()
print(p)
s=''
for j in b:
    s=s+str(j)+'+'
print(s+str(p))
