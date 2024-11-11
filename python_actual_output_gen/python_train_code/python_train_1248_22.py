n = int(input())
a = list(map(int, input().split()))
s = 0
k = 0
t = 0
for i in range(0, n):
    s = s + a[i]
while t < s//2:
    t = t + a[k]
    k = k+1
print(k)