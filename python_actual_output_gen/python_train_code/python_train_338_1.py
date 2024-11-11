a,b=input().split(':')
z='0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
c=[z.find(i) for i in a]
d=[z.find(i) for i in b]
for i in range(len(c)):
    if c[i]>0:
        break
c=c[i:]
for i in range(len(d)):
    if d[i]>0:
        break
d=d[i:]
if int(a,base=max(*c+[2])+1)>23 or int(b,base=max(*d+[2])+1)>59:
    print(0)
elif len(c)==len(d)==1:
    print(-1)
else:
    for i in range(max(*d+c)+1,61):
        e=0
        for j in range(len(c)):
            e+=i**j*c[-1-j]
        f=0
        for j in range(len(d)):
            f+=i**j*d[-1-j]
        if 0<=e<=23 and 0<=f<=59:
            print(i,end=' ')