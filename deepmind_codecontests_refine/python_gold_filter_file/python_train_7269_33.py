n,y=map(int,input().split())
y //= 1000
for i in range(n+1):
    p,q = divmod(y-n-i,4)
    if q == 0 and i <= p-i <= n:
        print(i,p-2*i, n-p+i)
        exit()
print("-1 "*3)