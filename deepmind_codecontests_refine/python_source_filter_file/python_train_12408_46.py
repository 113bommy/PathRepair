from collections import Counter 
l=list(map(int,input().split()))
flag=False
for i in range(l[0]+1,l[1]+1):
    res=Counter(str(i))
    flag=False
    for x in res.values():
        if x==1:
            flag=True
        else:
            flag=False
            break
    if flag==True:
        l.append(i)
        break
if flag==True:
    print(l[2])
else:
    print(-1)