n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

E=0;d=[]

for i in range(n):
    d.append(a[i]-b[i])

d.sort()

for i in range(n):
    if d[i]<=0:
        continue
    
    start=0
    end=i-1
    
    while start<end:
        k=(start+end)//2
        if d[k]+d[i]>0:
            end=k-1
        else:
            start=k+1
            
    for j in range(max(0,end),min(i,start)+1):
        if d[j]+d[i]>0:
            E+=i-j
            break
print(E)


