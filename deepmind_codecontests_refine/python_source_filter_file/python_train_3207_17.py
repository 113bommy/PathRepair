s = input()
n = len(s)

ans = [1]*n
for i,a = in enumerate(s):
    if a =="R":
        a2 = s[i+1]
        if a2 =="R":
            ans[i+2] += ans[i]
            ans[i] = 0

for i in range(n-1,-1,-1):
    a = s[i]
    if a =="L":
        a2 = a[i-1]
        if a2 =="L":
            ans[i-2] += ans[i]
            ans[i] = 0
print(*ans)