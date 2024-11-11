n,k=map(int,input().split())
l=[int(i) for i in input().split()]
if n==1:
    print(k-n)
    exit()
l.sort()
cnt=0 
while min(l)<k:
    cnt+=1 
    for i in range(0,n-1):
        if l[i]!=l[i+1]:
            l[i]+=1 
    l[n-1]+=1 
    #print(min(l))
print(cnt)