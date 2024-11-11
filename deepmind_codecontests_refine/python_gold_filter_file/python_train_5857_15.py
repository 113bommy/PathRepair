t=int(input())
for i in range(t):
    n,r = map(int,input().split())
    if n<=r:
        print((n-1)*n//2 +1)
    else:
        mina = min(n,r)
        print(mina*(mina+1)//2)