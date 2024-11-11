n = int(input())
a = list(map(int, input().split()))

max_problems = 1
current = 1
for i in range(1, n):
    if a[i] > 2*a[i-1]:
        current = 1
    else:
        current += 1
        if current > max_problems:
            max_problems = current

print(max_problems)
