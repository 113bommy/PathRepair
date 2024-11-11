

n = int(input())

a = []

for i in range(n): 
    a.append(int(input()))

a.sort()

b = [];

for i in range(int((n+1)/2)):
    b.append(a[i]*a[n-1-i])

res = sum(b)*2

if n%2 == 1:
    res-=b[len(b)-1]

print(res)
