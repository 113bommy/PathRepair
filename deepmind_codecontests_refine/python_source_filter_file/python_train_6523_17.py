n,k=map(int,input().split())
list1=list(map(int,input().split()))
list1.sort()
if(k==0):
    m=-1
else:
    m=list1[(k-1)]
cnt=0
for i in list1:
    if(m>=i):
        cnt+=1
if(k!=cnt or m<1):
    print(-1)
else:
    print(m)