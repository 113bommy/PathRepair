n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)

def sim(ct):
    ops = sum(ct-a[i] for i in range(n))
    
    return ops >= ct

l = a[0]
r = 10**9+1
ans = r

while l <= r:
    mid = (l+r)//2
    
    if sim(mid):
        ans = min(ans, mid)
        r = mid-1
    else:
        l = mid+1
        
print(ans)