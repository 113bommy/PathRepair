n,c = map(int,input().split())
a = list(map(int,input().split()))

if(n==1): print(1)
else:
    count = 0
    for i in range (1,n):
        if(a[i] - a[i-1] <= c):
            count += 1
        else:
            count = 1
    print(count)