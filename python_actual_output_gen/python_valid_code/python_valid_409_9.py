n = int(input())
a = list(map(int,input().split()))
a.sort()

if n == 1:
    print(2)
    exit()

for i in range(1,n):
    a[i] = min(a[i-1]+1,a[i])

print(max(a) + 1)
