n = int(input())
p = list(map(int,input().split()))

a = [0] * n
b = [0] * n
c = []

for i in range(n):
    a[i] = 30000*(i+1)
    b[i] = 30000*(n-i-1)

for i in range(n):
    k = p[i]
    b[k-1] += i

res = ''
ans = ''
for i in range(n):
    if i == n-1:
        res += str(a[i])
        ans += str(b[i])
    else:
        res += str(a[i]) + ' '
        ans += str(b[i]) + ' '

print(res)
print(ans)