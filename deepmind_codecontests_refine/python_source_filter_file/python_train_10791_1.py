n=int(input())
if n<=2:
    print(0)
    exit()
a=list(map(int,input().split()))
b=a.copy()
k1=0
q=b[1]-b[0]
for i in range(2,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k1+=1
    elif b[i-1]+q-b[i]==-1:
        b[i]-=1
        k1+=1
    elif b[i-1]+q-b[i]==0:
        pass
    else:
        k1=n+1
        break
b=a.copy()
k2=2
b[0]-=1
b[1]-=1
q=b[1]-b[0]
for i in range(2,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k2+=1
    elif b[i-1]+q-b[i]==-1:
        a[i]-=1
        k2+=1
    elif b[i-1]+q-b[i]==0:
        pass
    else:
        k2=n+1
        break
b=a.copy()
k3=2
b[0]+=1
b[1]+=1
q=b[1]-b[0]
for i in range(2,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k3+=1
    elif b[i-1]+q-b[i]==-1:
        b[i]-=1
        k3+=1
    elif b[i-1]+q-a[i]==0:
        pass
    else:
        k3=n+1
        break
b=a.copy()
k4=1
b[1]+=1
q=b[1]-b[0]
for i in range(2,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k4+=1
    elif b[i-1]+q-b[i]==-1:
        b[i]-=1
        k4+=1
    elif b[i-1]+q-b[i]==0:
        pass
    else:
        k4=n+1
        break
b=a.copy()
k5=1
b[1]-=1
q=b[1]-b[0]
for i in range(1,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k5+=1
    elif b[i-1]+q-b[i]==-1:
        b[i]-=1
        k5+=1
    elif b[i-1]+q-b[i]==0:
        pass
    else:
        k5=n+1
        break
b=a.copy()
k6=1
b[0]+=1
q=b[1]-b[0]
for i in range(2,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k6+=1
    elif b[i-1]+q-b[i]==-1:
        b[i]-=1
        k6+=1
    elif b[i-1]+q-b[i]==0:
        pass
    else:
        k6=n+1
        break
b=a.copy()
k7=1
b[0]-=1
q=b[1]-b[0]
for i in range(2,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k7+=1
    elif b[i-1]+q-b[i]==-1:
        b[i]-=1
        k7+=1
    elif b[i-1]+q-b[i]==0:
        pass
    else:
        k7=n+1
        break
b=a.copy()
k8=2
b[0]+=1
b[1]-=1
q=b[1]-b[0]
for i in range(2,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k8+=1
    elif b[i-1]+q-b[i]==-1:
        b[i]-=1
        k8+=1
    elif b[i-1]+q-b[i]==0:
        pass
    else:
        k8=n+1
        break
b=a.copy()
k9=2
b[0]-=1
b[1]+=1
q=b[1]-b[0]
for i in range(2,n):
    if b[i-1]+q-b[i]==1:
        b[i]+=1
        k9+=1
    elif b[i-1]+q-b[i]==-1:
        b[i]-=1
        k9+=1
    elif b[i-1]+q-b[i]==0:
        pass
    else:
        k9=n+1
        break
ans=min(k1,k2,k3,k4,k5,k6,k7,k8,k9)
if ans==n+1:
    print(-1)
else:
    print(ans)
        
    

        
