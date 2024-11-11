n,m=map(int,input().split())
list1=list(map(int,input().split()))
list2=list(map(int,input().split()))
ll=[]
for i in range(n):
    l=[]
    for j in range(m):
        l.append(list1[i]&list2[j])
        l.sort()
    ll.append(l)
    
xx=2**10
for i in range(1,2**10):
    x=i
    ff=0
    for j in range(n):
        f=0
        for k in range(m):
            if(x|ll[j][k]==x):
                f=1
                break
        if(f==0):
            ff=1
            break
    if(ff==0):
        if(x<xx):
            xx=x
    
print(xx)