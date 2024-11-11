n = int(input())
a = list(map(int, input().split()))

p1 = 1
p2 = 10**6
for i in range(len(a)):
    if a[i] >= 500000:
        p2 = a[i]
        break
    p1 = a[i]

print(max(p1-1, 10**6 - p2))