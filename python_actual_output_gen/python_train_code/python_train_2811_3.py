n=int(input())
sp=list(map(int,input().split()))
zn=list(map(int,list(input())))+[0]
u=[]
sr=[]
h=0
for i in range(len(zn)):
    if zn[i]==0:
        u.append((h,sp[i]))
        h+=1
    else:
        u.append((h,sp[i]))
u.sort()

for el in u:
    sr.append(el)
if sr==sorted(sp):
    print('YES')
else:
    print('NO')