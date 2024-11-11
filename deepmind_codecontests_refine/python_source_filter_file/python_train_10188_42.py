n = int(input())
p = [int(i) for i in input().split()]

a = [30000*i for i in range(n)]
b = [30000*(n-i) for i in range(n)]

for i,v in enumerate(p):
    a[i] += v

print(a)
print(b)