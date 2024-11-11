n,k = map(int,input().split())
lst = list(map(int,input().split()))
lst2 = list(map(int,input().split()))
ans = 0
for i in range(n):
    if lst2[i] == 1:
        ans += lst[i]
lst3 = [0]*n
if lst2[0] == 0:
    lst3[0] = lst[0]

for i in range(1,n):
    if lst2[i] == 0:
        lst3[i] = lst[i] + lst3[i-1]
    else:
        lst3[i] = lst3[i-1]
best = 0
best = lst3[k-1]
for i in range(k+1,n):
    sum1 = lst3[i] - lst3[i-k]
    best = max(sum1,best) 
print(ans+best)