n=int(input())
for _ in range(n):
    m=int(input())
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    if sum(a)>sum(b):
        print("NO")
    else:
        k=-1
        for i in range(m):
            if a[i]==b[i]:
                if k==-1:continue
                else: break
            else:
                if k==-1:
                    k=b[i]-a[i]
                a[i]+=k
        if a==b:
            print("YES")
        else: print("NO")