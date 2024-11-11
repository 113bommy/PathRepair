
t=int(input())

for _ in range(t):
    n,m,k=map(int,input().split())

    if n*(n-1)//2<m or k-2<0:
        print("NO")
        continue

    if k==2:
        if m==0:
            print("YES")
        else:
            print("NO")
    else:
        if k==3:
            if n*(n-1)//2==m:
                print("YES")
            else:
                print("NO")
        else:
            print("YES")