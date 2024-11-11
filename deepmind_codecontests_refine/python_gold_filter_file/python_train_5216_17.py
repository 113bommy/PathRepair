n = int(input())
a = list(map(int, input().split()))
m = 0
i = 0
while i < n:
    b = 1
    j = i + 1
    while j < n and a[j] <= a[j - 1] * 2:
        j += 1
        b += 1
    m = max(b, m)
    i = j
m = max(b, m)
print(m)
        
