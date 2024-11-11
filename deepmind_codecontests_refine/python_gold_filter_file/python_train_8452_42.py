for _ in range(int(input())):
    n,x,a,b=map(int,input().split())
    if a>b:
        left=b
        right=a
    else:
        left=a
        right=b
    while left>1 and x>0:
        left-=1
        x-=1
    while x>0 and right<n:
        right+=1
        x-=1
    print(abs(left-right))

    