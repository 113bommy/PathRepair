n,k = map(int,input().split())
lists = list(map(int,input().split()))
sums = sum(lists)
l,r = 0,10**1000
m = (l+r)//2
while r-l != 1:
    if 2*(sums+k*m) >= (2*k-1)*(len(lists)+m):
        r = m
        m = (l+r)//2
    else:
        l = m
        m = (l+r)//2
print(r)
    