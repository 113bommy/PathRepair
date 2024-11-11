n=int(input())
x1,y1,x2,y2=[int(x) for x in input().split()]
st=[]
et=[]
ok=1

if x1==x2 or y1==y2:
    ok=0

for i in range(n):
    a,b,u,w=[int(x) for x in input().split()]
    for x,v,s,e in ((a,u,x1,x2),(b,w,y1,y2)):
        if v==0:
            if not(s<=x<=e):
                ok=0
        else:
            t1=(s-x)/v
            t2=(e-x)/v
            st+=[min(t1,t2)]
            et+=[max(t1,t2)]

#print(st,et)            
            
if max(st)<=min(et) and min(et)>=0 and ok:
    print(max(max(st),0))
else:
    print(-1)