t=int(input())
for _ in range(t):
    n=int(input())
    x=[int(i) for i in input().split()]
    sm=2*sum(x)/(n*(n+1))
    if(int(sm)!=sm):
        print("NO")
        continue
    sm=int(sm)
    arr=[(x[-1]-x[0]+sm)/n]
    if(int(arr[0])!=arr[0] or arr[0]<0):
        print("NO")
        continue
    arr[0]=int(arr[0])
    flag=False
    for i in range(n-1):
        arr+=[(x[i]-x[i+1]+sm)/n]
        if(int(arr[i+1])!=arr[i+1] or arr[i+1]<=0):
            print("NO")
            flag=True
            break
        arr[i+1]=int(arr[i+1])
    if(flag):
        continue
    print("YES")
    print(' '.join([str(x) for x in arr]))
    
    
    