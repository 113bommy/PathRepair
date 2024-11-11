n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

s = 0
l = 0
for i in range(n):
    if l == k:
        break
    
    if (a[i] - s <= 0):
        continue
    else:
        print(a[i] - s)
        s = a[i]
        l += 1
        
for i in range(l, k):
    print(0)