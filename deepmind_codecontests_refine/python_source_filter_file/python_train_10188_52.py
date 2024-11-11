n = int(input())
p = [int(i) for i in input().split()]

a = [i*10000 for i in range(1,n+1)]
b = [(n-i+1)*10000 for i in range(1, n+1)]
c = [0 for i in range(n)]

for i in range(n):
    c[i] = a[i] + b[i]

for i in range(n-1):
    if(p[i] > p[i+1]):
        b[p[i+1]-1] +=  c[p[i]-1] - c[p[i+1]-1] + 1
        c[p[i+1]-1] +=  c[p[i]-1] - c[p[i+1]-1] + 1
    else:
        a[p[i+1]-1] += c[p[i]-1] - c[p[i+1]-1] + 1
        c[p[i+1]-1] += c[p[i]-1] - c[p[i+1]-1] + 1

print(" ".join(map(str, a)))
print(" ".join(map(str, b)))
