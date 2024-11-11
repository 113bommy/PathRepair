for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input()]
    flag=True
    for i in range(n,0,-1):
        if a[i-1]==0:
            if i>(n//2):
                print(1,i,1,i-1)
            else:
                print(i,n,i+1,n)
            flag=False
            break
    if flag:
        print(1,n-1,2,n)
