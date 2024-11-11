import math
s = input().split()
n = int(s[0])
k = int(s[1])

div = []

for j in range(math.trunc(math.sqrt(n))):
    i = j + 1
    if (n%i == 0):
        div.append(n//i)
        div.append(i)

div.sort()
div.reverse()

u = 0
for q in div:
    if (n/q >= k/2 + k*k/2):
        u = q
        break

if (u == 0):
    print(-1)
else:
    for i in range(1,k):
        print(i*u)
        n -= i*n
    print(n)


