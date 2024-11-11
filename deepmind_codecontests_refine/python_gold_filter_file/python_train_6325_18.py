N,K=map(int,(input().split(" ")))
a=list(map(int,(input().split(" "))))
j1=1
j2=1
co=0
if(N%2==0):
    M=N//2
else:
    M=N//2+1
i=0
while(j1!=0 and i<N):
    if(a[i]<=K and j1==1):
        co=co+1
    else:
        j1=0
        pos=i
    i=i+1
if(j1==0):
    i=pos+1
    j=N-1
    while(j>=i and j2!=0):
        if(a[j]<=K and j2==1):
            co=co+1
        else:
            j2=0
        j=j-1
print(co)