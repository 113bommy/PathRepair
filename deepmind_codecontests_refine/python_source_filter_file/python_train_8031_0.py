rc=input().split()
r=int(rc[0])
c=int(rc[1])
l=[]
for i in range(r):
    l.append([i for i in input()])
pos=[0,0]
last=[0,0]
count=0
for i in range(r-1):
    j=pos[1]
    while j>=0 and j<c:
        if l[i][j]=="W":
            count+=abs(j-pos[1])
            pos[1]=j
        if i%2==0:
            j+=1
        else:
            j-=1
    mark=0
    if i%2==0:    
        for j in range(pos[1],c):
            if l[i+1][j]=="w":
                last=[i+1,j]
                mark=1
        if mark==1:
            count+=abs(last[1]-pos[1])+1
            pos=last
        else:
            count+=1
            pos[0]+=1
    else:
        for j in range(pos[1],-1,-1):
            if l[i+1][j]=="W":
                last=[i+1,j]
                mark=1
        if mark==1:
            count+=abs(last[1]-pos[1])+1
            pos=last
        else:
            count+=1
            pos[0]+=1
if (r-1)%2!=0 :
    j=pos[1]
    for i in range(j,-1,-1):
        if l[r-1][i] =="W":
            count+=pos[1]-i
            pos[1]=i
else:
    j=pos[1]
    for i in range(j+1,c):
        if l[r-1][i] =="W":
            count+=i-pos[1]
            pos[1]=i

for i in range(r-1,-1,-1):
    if "W" not  in l[i]:
        count-=1
    else:
        break

print(count if count>0 else 0)
