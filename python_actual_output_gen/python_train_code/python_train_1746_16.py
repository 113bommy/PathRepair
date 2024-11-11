a,b,ax,bx =[],[],[],[]

for i in range(int(input())):
    _1,n = map(int,input().split())
    a.append(_1)
    ax.append(n)
    

for i in range(int(input())):
    n,_1 = map(int,input().split())
    b.append(n)
    bx.append(_1)

pa,pb=0,0
if max(b)-min(ax) > 0:
    pa = max(b)-min(ax)
if max(a)-min(bx) > 0:
    pb = max(bx)-min(a)

if pa>=pb :
    print(pa)
elif pb>pa :
    print(pb)
else :
    print(0)