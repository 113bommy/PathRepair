n = int(input())
a = [int(i) for i in input().split()]
a.sort()
s = 0
t = 0
for i in range(n):
    s = s + a[i]
t = s*n
if n >= 3:
    for i in range(n-2):
        t = t - a[i]*(n-2-i)
else:
        t = s
print(t)
        
    