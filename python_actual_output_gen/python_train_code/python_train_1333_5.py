n,k = list(map(int, input().split()))
a  = list(map(int, input().split()))

if n==1:
    print(a[0]+k)
    exit(0)

a = sorted(a)
a = a[int(n/2):]+[10**10]
n= int(n/2)+2
m, next = a[0], a[1]

ans,nans = m,1
while k>0:
    dx = k/nans
    dy = next - ans
    if dx<=dy:
        ans = ans + dx
        break
    k -= dy*nans
    ans = next
    nans +=1
    next = a[nans]

print(ans)    
    