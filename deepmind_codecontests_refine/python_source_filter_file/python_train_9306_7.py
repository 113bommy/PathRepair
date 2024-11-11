[d, n] = map(int, input().split())
heights = list(map(int, input().split()))
count = 0
 
for i in heights:
    for j in heights:
        if abs(j - i) <= n:
            count += 1
print(count)
    