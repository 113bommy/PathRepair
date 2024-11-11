n,m,k=map(int,input().split())
i,l,q,w,t=n*m,[],1,1,0
while i>0:
    l+=[q,w]
    i-=1
    if i==0:break
    if w==n or(w==1and t):q+=1;l+=[q,w];t=1-t;i-=1
    w+=(-1)**t
for i in range(0,4*k-4,4):print(*([2]+l[i:i+4]))
print(*([n*m-2*k+2]+l[k*4-4:]))