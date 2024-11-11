n,k=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(n)]
c=0
for a,b in l:
    c+=b
    if c>=k:
        print(a)
        exit(0)
