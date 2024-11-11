u = list(map(int, list(input())))
n = len(u)
d = []
for i in range(1, 1001):
    d.append(list(map(int, list(str(i * i)))))
ans = []
for k in d:
    if len(k) > n:
        break
    m = 0
    j = 0; i = 0
    while i < n and j < len(k):
        if u[i] == k[j]:
            i += 1; j += 1
        else:
            i += 1
            m += 1
    if j == len(k):
        ans.append(m + (n - i))
if len(ans) == 0:
    print(-1)
else:
    print(min(ans))
    
            

