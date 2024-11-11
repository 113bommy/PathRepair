n,m=map(int,input().split())
m=m%((n*(n+1))//2)
if m == 0:
    print("0")
else:
    for i in range(n+1):
        if i > m:
            print(m)
            break
        else:
            m-=i