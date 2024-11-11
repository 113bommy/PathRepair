n,m=[int(x) for x in input().split()]
bys = [int(x) for x in input().split()]
grls=  [int(x) for x in input().split()]
i = 0
sb=[0]*n
sg=[0]*m
for i in range(1,len(bys)):
    sb[bys[i]] = 1
for i in range(1,len(grls)):
    sg[grls[i]] = 1
while 1:
    nxby = i%n
    nxgr = i%m
    if sb[nxby] == 1 or sg[nxgr] == 1:
        sb[nxby] = 1
        sg[nxgr] = 1
    if n*m < i:
        break
    i+=1
if sum(sb) + sum(sg) >= m+n:
    print('Yes')
else:
    print('No')
    
    
