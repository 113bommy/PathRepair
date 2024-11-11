xc=[]
for item in range(3):
    a=[int(x) for x in input().split()]
    xc.append(a)
cx=[]
xc.sort()
tot=[]
counter=0
for item in xc:
    cx.append((item[1],item[0]))
    cx.sort()
for item in range(xc[0][0],xc[2][0]+1):
    tot.append(str(item)+' '+str(cx[1][0]))
    counter+=1
if xc[0][1]>cx[1][0]:
    for item in range(cx[1][0]+1,xc[0][1]+1):
        tot.append(str(xc[0][0])+' '+str(item))
        counter+=1
elif xc[0][1]<cx[1][0]:
    for item in range(xc[0][1],cx[1][0]):
        tot.append(str(xc[0][0])+' '+str(item))
        counter+=1
if xc[2][1]>cx[1][0]:
    for item in range(cx[1][0]+1,xc[2][1]+1):
        tot.append(str(xc[2][0])+' '+str(item))
        counter+=1
elif xc[2][1]<cx[1][0]:
    for item in range(xc[2][1],cx[1][0]):
        tot.append(str(xc[2][0])+' '+str(item))
        counter+=1
if xc[1][1]>cx[1][0]:
    for item in range(cx[1][0]+1,xc[1][1]+1):
        tot.append(str(xc[1][0])+' '+str(item))
        counter+=1
elif xc[1][1]<cx[1][0]:
    for item in range(xc[1][1],cx[1][0]):
        tot.append(str(xc[1][0])+' '+str(item))
        counter+=1
print(counter)
for item in tot:
    print(item)

    
