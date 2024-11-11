n,S=map(int,input().split())
s=S*2+1
h1,m1=map(int,input().split())
if h1*60+m1>S+1:res=0
else:res=-1
lst,mas=[h1*60+m1],[[h1,m1]]
for i in range(n-1):
    h2,m2=map(int,input().split())
    mas.append([h2,m2])
    diff=h2*60+m2
    lst.append(diff)
if res==-1:
    for i in range(n-1):
        x=lst[i+1]-lst[i]
        if x-s-1>=0:res=lst[i]+S+1;break
    if res==-1:res=lst[-1]+S+1
    print(res//60,res%60)
else:print(0,0)