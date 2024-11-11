a = list(map(int,input().split()))
flag = True
for i in range(0,4):
    for g in range(i+1,5):
        for k in range(g+1,6):
            sum1 = a[i] + a[g] + a[k]
            sum2 = sum(a) - sum1
            if sum1 == sum2:
                flag = False
else:
    print("NO" if flag else "YES")