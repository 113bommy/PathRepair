for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    f=1
    for i in range(1,n-1):
        if abs(a[i+1]-a[i])>1:
            print("YES")
            print(i,i+1)
            f=0; break
    if f: print("NO")