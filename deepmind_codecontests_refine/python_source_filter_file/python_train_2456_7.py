##n = int(input())
##a = list(map(int, input().split()))
##print(' '.join(map(str, res)))

[n, k] = list(map(int, input().split()))
a = list(map(int, input().split()))

s = set()
for i in range(n):
    s.add(a[i]%k)
if len(s) > 1:
    print('-1')
    exit(0)
amin = 1e9
for i in range(n):
    amin = min(amin, a[i])
res = 0
for i in range(n):
    res += (a[i]-amin)//k
print(res)

