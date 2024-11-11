n,m=list(map(int,input().split()))
a=list(map(int,input().split()))
a.sort()
l=[]
y=[0]
for i in range(m):
    if i==0:
        l.append(1)
        continue
    if a[i]==a[i-1]:
        l[-1]+=1
    else:
        l.append(1)
for i in range(1,101):
    z=0
    lcopy = l.copy()
    for k in range(len(lcopy)):
        while lcopy[k]-i>=0:
            lcopy[k]-=i
            z+=1
    if z>=n:
        y.append(i)
    else:
        break
print(y[-1])
