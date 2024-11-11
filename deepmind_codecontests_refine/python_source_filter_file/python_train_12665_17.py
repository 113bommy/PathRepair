n,k=map(int,input().split())
a=[]
for i in range(n):
    a.append(input())
m,x,y=-1,0,0
for i in range(n):
    for j in range(n):
        if a[i][j]=='#':continue
        R=0;
        while j+R<n:
            if a[i][j+R]=='#':break
            if R==k-1:break
            R+=1
        L=0;
        while j-L>=0:
            if a[i][j-L]=='#':break
            if L==k-1:break
            L+=1
        U=0;
        while i-U>=0:
            if a[i-U][j]=='#':break
            if U==k-1:break
            U+=1
        D=0;
        while i+D<n:
            if a[i+D][j]=='#':break
            if D==k-1:break
            D+=1
        z=min(k,max(0,L+R-k))+min(k,max(0,U+D-k))
        if z>m: m,x,y=z,j,i
print(y+1,x+1)

            
        
        
