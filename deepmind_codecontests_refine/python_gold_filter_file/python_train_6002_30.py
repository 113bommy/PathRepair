n,m=map(int,input().split())
p=m%(n*(n+1)/2)
for i in range(1,n+1):
    if p>=i:
        p=p-i
    else:
        print(int(p))
        exit()
