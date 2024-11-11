n,m,k=map(int,input().split( ))
a=list(map(int,input().split( )))
b=list(map(int,input().split( )))
d={}
ges=0
memory=0
for i in range(n):
    d[a[i]]=i+1
for i in b:
    scr=1+d[i]//k
    ges=ges+scr
    if not d[i]==1:
        d[i]-=1
        memory=a[d[i]-1]
        d[memory]+=1
        a[d[i]-1]=i
        a[d[i]]=memory
print(ges)
        
