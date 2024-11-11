n, k = map(int, input().split())
b = list(map(int, input().split()))
a = list(map(int, input().split()))
l=0
h=10**10
res = 0
while l <= h :
    mid = (l+h)//2
    sum = 0
    for i in range(n) :
        sum += max(b[i]*mid - a[i],0) 
    if sum <= k:
        res = mid
        l = mid+1
    else:
        h = mid-1
print(res)