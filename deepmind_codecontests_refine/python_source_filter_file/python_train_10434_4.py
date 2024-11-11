t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    arr=[int(i) for i in input().split()]
    flag=0
    while(arr!=[0 for i in arr]):
        b=[x%k for x in arr]
        arr=[x//k for x in arr]
        if sum(b)>1:
            flag=1
            print("NO")
            break
    if flag==1:
        print("YES")
        
    