from collections import Counter
n,m = list(map(int,input().split()))
a = [[0 for i in range(n)] for i in range(m)]
print(a)
for i in range(n):
    b = list(map(str,input()))
    for ind,el in enumerate(b):
        a[ind][i] = el

point = list(map(int,input().split()))
ans = 0
for i in range(m):
    ans += point[i]*(Counter(a[i]).most_common(1)[0][1])
print(ans)