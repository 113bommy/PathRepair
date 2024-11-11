n=int(input())
m=0
if((n%2)==0):
    t=n+2
    m=int(t//2)
else:
    t=n+1
    m=int(t//2)
print(m)
r,c=1,1
print(r,c)
for i in range(1,n):
    if(c==m):
        r=r+1
    if(c<m):
        c=c+1
    print(r,c)