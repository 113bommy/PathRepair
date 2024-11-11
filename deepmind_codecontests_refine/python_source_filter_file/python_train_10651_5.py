n=int(input())
l1=[]
l2=[0]*n
tx,pz,girls=[0]*n,[0]*n,[0]*n
for i in range(n):
    l1.append(input().split())
    l2[i]=[]
    for j in range(int(l1[i][0])):
        l2[i].append(input().replace('-',''))
        p=1
        for _ in range(1,6):
            if l2[i][j][_]>=l2[i][j][_-1]:
                p=0
                break
        if p:
            pz[i]+=1
        elif l2[i][j].count(l2[i][j][0])==6:
            tx[i]+=1
        else:
            girls[i]+=1

t,p,g=max(tx),max(pz),max(girls)
at,ap,ag='','',''
for i in range(n):
    if tx[i]==t:
        at+=l1[i][1]+','
    if pz[i]==p:
        ap+=l1[i][1]+','
    if girls[i]==g:
        ag+=l1[i][1]+','
at=at[:-1]
ap=ap[:-1]
ag=ag[:-1]
    
print('If you want to call a taxi, you should call: '+at+'.')
print('If you want to order a pizza, you should call: '+ap+'.')
print('If you want to go to a cafe with a wonderful girl, you should call: '+ag+'.')