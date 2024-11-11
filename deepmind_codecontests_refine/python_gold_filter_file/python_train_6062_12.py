t = int(input())
for i in range(t):
    n , m = map(int,input().split())
    arr = list(map(int,input().split()))
    if(arr[0]==m):
        print(m)
        continue
    if(n==1):
        print(arr[0])
        continue
    j = 1
    flag = 0
    while(j<n):
        arr[0]+=arr[j]
        if(arr[0]>=m):
            flag = 1
            break
        j+=1
    if(flag==1):
        print(m)
    else:
        print(arr[0])

