n = input().split()
d = int(n[1])
n = int(n[0])
res = 0
a = list(map(int,input().split()))
for i in range(1,n):
    if a[i] <= a[i-1]:
       res = res + (a[i-1]-a[i]) // d +1
       a[i] += (a[i-1]-a[i]) // d +1
print(res)