n = int(input())
t = input()
ans = list()
cur = ''
used = set()
for i in range(len(t)):
    if(t[i] not in used):
        if(len(cur) > 0):ans.append(cur)
        cur = t[i]
        used.add(t[i])
    else: cur += t[i]
ans.append(cur)
if(len(ans) < n):print("No")
else:
    print("Yes")
    for i in range(n,len(ans)):
        ans[n-1] += ans[i]
    for i in range(n):
        print(ans[i])

