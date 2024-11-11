n,k=map(int,input().split())
a=list(map(int,input().split()))

l=0
r=1e9+5

while l+1!=r:
    m = (l+r)//2
    cnt = 0
    for x in a:
        cnt += (x-1)//m
    if cnt <= k:
        r = m
    else:
        l = m
print(int(r))