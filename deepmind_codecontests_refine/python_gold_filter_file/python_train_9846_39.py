n = int(input())
a = list(map(int, input().split()))

S = 0
if len(a) == 1:
    S = 0
else:
    max_a = max(a)
    for i in range(n):
        diff = max_a - a[i]
        if diff > 0:
            S += diff
print (S)