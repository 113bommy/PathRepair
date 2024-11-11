times = int( input())
s= set()
n= set()
net= set()
ans=0
for i in range(times-1):
    temp= input().split()
    if len(net)==1 or len(n)==25:
       if temp[0]=='!' or temp[0]=='?':
           ans+=1
       continue
    if temp[0]=='.':
        for j in temp[1]:
            n.add(j)
    elif temp[0]=='!':
        m=set()
        if len(s)!= 0:
            for k in s:
                if k in temp[1]:
                    m.add(k)
        else :
            for k in temp[1]:
                m.add(k)
        for k in s:
            if k not in m:
                n.add(k)
        for k in temp[1]:
            if k not in m:
                n.add(k)
        s=m
    elif temp[0]=='?':
        if temp[1] in s :
            s.remove(temp[1])
            n.add(temp[0])
        else:
            n.add(temp[0])
    net=s-n
print(ans)
