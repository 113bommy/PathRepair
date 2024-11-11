n, k = map(int, input().split())
p = list(map(int, input().split()))
l = []
a1 = 0
a2 = 1
for i in range(n):
    if p[i]>n-k:
        a1 += p[i]
        l.append(i)
if k>1:
    for i in range(1,k):
        a2 = a2*(l[i]-l[i-1])
print(a1,a2//998244353)
