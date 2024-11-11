n=input()
l=len(n)
v=[]
for i in range(l):
    if n[i] not in v:
        v.append(n[i])
    else:
        continue
a=len(str(''.join(v)))
if l%2==0:
    print('CHAT WITH HER')
else:
    print('IGNORE HIM!')