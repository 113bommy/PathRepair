from math import ceil,floor

n = int(input())
a = input().split(' ')
arr=[]
o,e,arr=ceil(n/2),floor(n/2),[]
for i in a:
    num = int(i)
    if num%2!=0:
        o=o-1
    elif num>0:
        e=e-1
    arr.append(num)
oa,ea,of,ef,cnt,f=[],[],False,False,0,True
ans=0
e1,o1=[],[]
#print(arr)
for i in arr:
    if i==0:
        cnt=cnt+1
    else:
        if f:
            if i%2==0:
                e1.append(cnt)
                ef=True
            else:
                o1.append(cnt)
                of=True
            cnt=0
        elif of:
            #print('o')
            if i%2==0:
                ef=True
                ans=ans+1
                of=False
                #print('!')
            else:
                oa.append(cnt)
            cnt=0
        elif ef:
            #print('e')
            if i%2==0:
                ea.append(cnt)
            else:
                of=True
                ef=False
                ans=ans+1
                #print('!')
            cnt=0
        else:
            #print('n')
            if i%2==0:
                ef=True
            else:
                of=True
        f=False
if cnt==n:
    print(min(1,n-1))
else:
    if of:
        o1.append(cnt)
    elif ef:
        e1.append(cnt)
    oa.sort()
    ea.sort()
    o1.sort()
    e1.sort()
    op,ep = len(oa),len(ea)
    for i in oa:
        if o>=i:
            op=op-1
            o=o-i
        else:
            break

    for i in ea:
        if e>=i:
            ep=ep-1
            e=e-i
        else:
            break
    for i in o1:
        if o>=i:
            o=o-i
        else:
            ans=ans+1

    for i in e1:
        if e>=i:
            e=e-i
        else:
            ans=ans+1
    ans=ans+(2*(ep+op))
    print(ans)        
                