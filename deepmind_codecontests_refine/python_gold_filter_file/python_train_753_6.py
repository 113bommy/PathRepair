for _ in range(int(input())):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    if n==1:
        print(0)
    else:
        d=max(arr)
        a=min(arr)
        for i in range(n):
            arr[i]=d-arr[i]
        if((k-1)%2==0):
            print(*arr)
        else:
            q=d-a
            for j in range(n):
                
                print(q-arr[j],end=' ')
            print('\n')
