I = lambda: map(int, input().rstrip().split())
n = int(input())
a = list(sorted(I()))
t = 0
j = n - 1
for i in range(n // 2 + 1, -1, -1):
    if a[i] < a[j]:
        t += 1
        j -= 1
print(t)