n,L=map(int,input().split())

powers=[]
fir=1
for i in range(n):
    powers.append(fir)
    fir*=2
    
c=list(map(int,input().split()))

for i in range(1,n):
    c[i]=min(2*c[i-1],c[i])
cost=0
fincost=[]
#print(powers)
for i in range(n-1,-1,-1):
    cost+=(L//powers[i])*c[i]
    L=L%powers[i]
    if(L==0):
        fincost.append(cost)
        
    else:
        fincost.append(cost+c[i])
print(int(min(fincost)))