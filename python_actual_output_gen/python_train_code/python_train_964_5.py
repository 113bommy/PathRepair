n = int(input())
a = list(map(int,input().split()))

if(n==3):
    print(a[2]-a[0])
else:
    large = 0
    small = a[3]-a[1]
    index = 2

    for i in range (3,n-1):
        large = a[i]-a[i-2]
        if large < small:
            small = large
            index = i-1
    
    a.pop(index)
    print(max(a[i]-a[i-1] for i in range (1,n-1)))