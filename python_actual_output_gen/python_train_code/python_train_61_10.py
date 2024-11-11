n, k = map(int, input().split())
i = list(map(int, input().split()))
b = []
total = 0
a = 0
while a < n:
    total += a
    if total >= k:
        break
    a += 1
    
print(i[a-1-(total%k)])
