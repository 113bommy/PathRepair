n = int(input())
a = list(map(int, input().split()))

count = 0
for i in range(n):
    mini = a.index(min(a[i:]))
    if mini != i:
        a[i], a[mini] = a[mini], a[i]
        count += 1

print(' '.join(map(str, a)))
print(count)

