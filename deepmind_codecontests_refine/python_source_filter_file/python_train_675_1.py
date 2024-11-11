n = int(input())

b =  [[0] * 2 for i in range(n)]

for i in range(n):
    a = [int(s) for s in input().split()]
    for j in range(n):
        b[i][0] += a[j]
        b[i][1] = i 

b.sort()
ans = [0]*n
sum = 0
for i in range(n - 1):
    ans[b[i][1]] = (b[i][0] - sum)// (n - 1 - i)
    sum += ans[b[i][1]]

ans[b[n - 1][1]] = sum + 1

s = ''
for i in range(n):
    s += str(ans[i]) + ' '
print(s)
