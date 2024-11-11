n,s = map(int , input().split())
price = list(map(int , input().split()))
def find(k):
    new = sorted([price[i]+(i+1)*k for i in range(n)])
    tot = sum(new[:k])
    if tot<=s:
        return tot
    return 0
l,h = 0,n-1
while l<h:
    mid = int((l+h)/2)
    if find(mid):
        l=mid+1
    else:
        h=mid-1
print(l,find(l))