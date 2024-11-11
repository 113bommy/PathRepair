a=input()
b=input()
coa=0
cob=0
for i in a:
    if i=='1': coa+=1
for i in b:
    if i=='1': cob+=1

if coa+(coa&1)>=cob:print('YES')
else:print('NO')
