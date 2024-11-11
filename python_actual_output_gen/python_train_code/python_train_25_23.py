n= int(input())
a = list(map(int,input().split()))
res = 0
for i in range(n):
    if a[i] <= 1000:
        res = max(res,a[i] - 1)
    else:
        res = max(res, (10**6) - a[i])
print(res)
    
