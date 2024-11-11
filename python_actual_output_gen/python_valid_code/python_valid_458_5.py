for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if n%2==0:
        print("YES")
    else:
        ver=False
        for i in range(1,n):
            if a[i]<a[i-1]:
                ver=True
                break
        if ver:
            print("YES")
        else:
            print("NO")