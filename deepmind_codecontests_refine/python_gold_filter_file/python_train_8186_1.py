from collections import deque 
l=input()
az=deque([])
z=deque([])
f=0
for i in range(len(l)):
    if l[i]=='0':
        if len(az)==0:
            z.append([i+1])
        else:
            az[0].append(i+1)
            z.append(az[0])
            az.popleft()
    else:
        #print(f)
        if len(z)==0:
            f=1
            break 
        else:
            z[0].append(i+1)
            az.append(z[0])
            z.popleft()
if f==1 or len(az)!=0:
    print(-1)
else:
    print(len(z))
    for i in range(len(z)):
        print(len(z[i]),*z[i],sep=" ")
            