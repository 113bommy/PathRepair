n,m=map(int,input().split())
d=[]
s1=s2=c=0
for i in range(n):
    x,y=map(int,input().split())
    s1+=x
    s2+=y
    if x-y>0:
        d.append(x-y)
if s2>m:
    print(-1)
    exit()
if s1<m:
    print(0)
    exit()
d.sort(reverse=True)
r=s1-m
for v in d:
    r-=v
    c+=1
    if r<=0:
        break
print(c)