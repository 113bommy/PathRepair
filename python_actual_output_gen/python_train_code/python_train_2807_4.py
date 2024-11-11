d1=dict()
d2=dict()
for _ in range(int(input())):
    x,y = map(int, input().split())
    if x+y in d1:
        d1[x+y]+=1
    else:
       d1[x+y]=1
    if x-y in d2:
        d2[x-y]+=1
    else:
       d2[x-y]=1
#print(d1)
#print(d2)
attack1=0
attack2=0
for v in d1.values():
    if v>=2:
        attack1+=v*(v+1)//2
for v in d2.values():
    if v>=2:
        attack2+=v*(v+1)//2
print(max(attack1,attack2))