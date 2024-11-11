n,p = map(int,input().split())
a = list(map(int,input().split()))
m = 0
for i in range(n):
    if a[i]%2 == 1:
        m += 1
if m==0 and p==1:
    print(0)
elif m==0 and p==0:
    print(2**(n))
else:
    print(2**(n-1))