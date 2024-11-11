n,k = map(int,input().split())
a = list(map(int,input().split()))
# 小課題１
# cost = 0
# for i in range(1,n):
#    if a[i] < a[i-1] + 1 :
#        cost += a[i-1] + 1 - a[i]
#        a[i] = a[i-1] + 1
# print(cost)

ans = 10**100
for i in range(1,2**n,2):
    if k != sum([ i>>j & 1 for j in range(n)]) :
        continue
    kijun = a[0]
    cost = 0
    for j in range(1,n):
        if ((i>>j) & 1) :
            if a[j] <= kijun :
                cost += (kijun + 1 - a[j])
                kijun = kijun + 1
            else :
                kijun = a[j]
        else :
            kijun = max(kijun,a[j])
    ans = min(ans,cost)
print(ans)
