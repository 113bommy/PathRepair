n = int(input())
a = input().split()
i = 0
v = 0
for i in range(n):
    v+=int(a[i])
print(v/n)