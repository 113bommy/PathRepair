n,m=map(int,input().split(' '))
arr=[]
mid=int((m+1)/2)
if(m%2==0):
    if(m==2):
        arr.append(mid)
        arr.append(mid+1)
    else:
        arr.append(mid)
        for i in range(1,mid):
            arr.append(mid+i)
            arr.append(mid-i)
        arr.append(m)
else:
    arr.append(mid)
    for i in range(1,mid):
        arr.append(mid-i)
        arr.append(mid+i)
for i in range(n//m):
    for j in range(m):
        print(arr[j])
for i in range(n%m):
    print(arr[i])

            
        
        
    
    
    
    
