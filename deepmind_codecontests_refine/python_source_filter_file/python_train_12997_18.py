from heapq import heapify, heapreplace
n = int(input())
a = list(map(int, input().split()))
a1 = a[:n]
heapify(a1)
a2 = a[n:2*n]
a3 = [-i for i in a[2*n:]]
heapify(a3)
b1 = [sum(a1)]
b2 = [sum(a3)]
for i in range(n):
    b1.append(a2[i]-heapreplace(a1, a2[i]))
    b2.append(-heapreplace(a3, -a2[n-i-1])-a2[n-i-1])
for i in range(n):
    b1[i+1] += b1[i]
    b2[i+1] += b2[i]
accu = []
mx = b1[0]
for i in b1:
    mx = max(mx, i)
    accu.append(mx)
ans = -10**12
mx = b2[0]
for i in range(n+1):
    mx = max(mx, b2[i])
    ans = max(ans, mx+accu[n-i])
print(ans)