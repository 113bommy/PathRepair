n=input().split( )
n=list(map(int,n))
r=0
for i in range(n[0],n[1]):
    na=str(i)
    l=[]
    for j in na:
        
        if j not in l:
            l.append(j)
    if (len(l)==len(na)):
        r=i
        break
    else:
        r=0
if r>0 :
    print(r)
else:
    print(-1)   
