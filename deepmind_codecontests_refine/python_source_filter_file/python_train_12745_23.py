x=list(map(int,input().split()))

n=x[0]
p=x[1]
k=x[2]

if(p-k>0):
    print("<<",end=' ')




for i in range(k):
    if(p+i-k>0):
        print(p+i-k,end=' ')

print("(",end='')
print(p,end='')
print(")",end=' ')


for i in range(1,k+1):
    if(p+i<=n):
        print(p+i,end=' ')
        
if(p+k<n):
    print(">>",end=' ')