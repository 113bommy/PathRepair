n = int(input())
a = list(map(int, input().split()))
x = min(a)
count = x * n
m = []
for i in range(n):
    if a[i]==x:
        m.append(i)
y = len(m)
z = m[0]
for i in range(y-1):
    m[i] = m[i+1] - m[i]
m[-1] = n - (m[-1] - z)
count+=max(m)
print(count)