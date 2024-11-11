n,k=map(int,input().split())
l=[int(i) for i in input().split()]
l.sort()
if max(l)-min(l)<=k:
    print(0)
    exit() 
maxlen=0 
for i in range(n):
    for j in range(i,n):
        if max(l[i:j+1])-min(l[i:j+1])<=k:
            maxlen=max(maxlen,j-i+1)
print(n-maxlen)