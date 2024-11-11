#%%
n = int(input())
a = list(map(int ,input().split()))

a.sort(reverse=True)
ans = []
for i in range(n):
    if i == 0:
        tmp = a[i]
    elif 1 <= i < n - 1:
        if a[i] > 0:
            ans.append(str(a[-1]) + ' ' +  str(a[i]))
            a[-1] -= a[i]
        else:
            ans.append(tmp + ' ' +  str(a[i]))
            tmp -= a[i]
    else:
        ans.append(str(tmp) + ' ' +  str(a[-1]))
        a = tmp - a[-1]
        print(a)

for i in range(len(ans)):
    x, y = map(int, ans[i].split())
    print(x, y)
