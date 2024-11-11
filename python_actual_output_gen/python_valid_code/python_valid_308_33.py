n,m=[int(x) for x in input().split()]
di=[]
for i in range(n):
    a,b=[int(x) for x in input().split()]
    b+=1
    for ii in range(a,b):
        di.append(ii)
li=list(set(di))
if len(li)==m:
    print(0)
    print()
else:
    ans=''
    count=0
    for i in range(1,m):
        if i not in li:
            ans+=str(i)+' '
            count+=1
    print(count)        
    print(ans[:-1]) 