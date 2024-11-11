n,k = map(int, input().split(' '))
alist = list(map(int,input().split()))
i = 0
count = 0
for i in range(0,n,1):
    if alist[i] <= k:
        count += 1
    else:
        break
if i < n-2:
    for j in range(n-1,i,-1):
        if alist[j] <= k:
            count += 1
        else:
            break
print(count)