a,b=map(int,input().split())
c=bin(a)[2:]
d=bin(b)[2:]
#print(d,c)
t1=len(c)
t2=len(d)
ans=0
for i in range(t1,t2+1):
    for j in range(0,i-1):
        #print(bin((1<<(i))-1-(1<<j))[2:],(1<<(i))-1-(1<<j))
        if ((1<<(i))-1-(1<<j)) in range(a,b+1):
            ans+=1
print(ans)
