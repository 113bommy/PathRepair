n = int(input())
p = [int(input()) for i in range(n)]
tl = 0
n2i = [-1 for i in range(n)]
for i in range(n):
    n2i[p[i]-1] = i
tmp = 1
for i in range(n-1):
    if n2i[i] < n2i[i+1]:
        tmp += 1
    else:
        tmp = 1
    tl = max(tl, tmp)

ans = n - tl
print(ans)