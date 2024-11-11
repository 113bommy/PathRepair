t= int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    flag=True
    if n%2:
        for i in range(n//2+1):
            if a[i]<i:
                flag=False
        for i in range(n//2+1,n):
            if a[i]<n-1-i:
                flag=False
    else:
        flag1=True
        flag2=True
        for i in range(n//2+1):
            if a[i]<i:
                flag1=False
        for i in range(n//2+1,n):
            if a[i]<n-i:
                flag1=False
        for i in range(n//2):
            if a[i]<i+1:
                flag2=False
        for i in range(n//2,n):
            if a[i]<n-1-i:
                flag2=False
        flag=any([flag1, flag2])
    
    if flag:
        print('Yes')
    else:
        print('No')
