n = int(input())
lst = list(map(int,input().split()))
cum = [None]*n
cum[0] = lst[0]
for x in range(1,n):
    cum[x] = ( cum[x-1] + lst[x])
print(cum)
q = int(input())
for x in range(0,q):
    l,r = map(int,input().split())
    #print(l,r)
    if l==1:
        print(cum[r-1]//10)
    else:
        ans = cum[r-1] - cum[l-2];
        print((ans//10))