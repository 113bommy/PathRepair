n=int(input())
c=input()
a=input()
buff=[[]for i in range(4)]
for i in range(n):
    if a[i]==c[i]=='0':
        buff[0].append(i)
    elif c[i]=='1' and a[i]=='0':
        buff[1].append(i)
    elif c[i]=='0' and a[i]=='1':
        buff[2].append(i)
    else:
        buff[3].append(i)
ans=[0]*n
while buff[1] and buff[2]:
    ans[buff[1].pop()]=1
    ans[buff[2].pop()]=2
if buff[1] or buff[2]:
    k=1 if len(buff[1])!=0 else 2
    while buff[k] and buff[3]:
        if k==1:
            ans[buff[k].pop()]=1
            ans[buff[3].pop()]=2
        else:
            ans[buff[3].pop()]=1
            ans[buff[k].pop()]=2
    if len(buff[k])>0:
        while buff[k] and buff[0]:
            if k==1:
                ans[buff[0].pop()]=1
                ans[buff[k].pop()]=2
            else:
                ans[buff[k].pop()]=1
                ans[buff[0].pop()]=2
if buff[1] or buff[2]:
    ans=[]
else:
    while len(buff[0])>1:
        ans[buff[0].pop()]=1
        ans[buff[0].pop()]=2
    while len(buff[3])>1:
        ans[buff[3].pop()]=1
        ans[buff[3].pop()]=2
    if buff[0] and buff[3]:
        i=0
        while i<n:
            if c[i]=='1' and a[i]=='0':
                ans[i]=2
                break
            i+=1
        if i==n:
            ans=[]
        else:
            ans[buff[0].pop()]=1
            ans[buff[3].pop()]=1
if len(ans)==0:
    print(-1)
else:
    for i in range(len(ans)):
        if ans[i]%2:
            print('{0} '.format(i+1),end='')