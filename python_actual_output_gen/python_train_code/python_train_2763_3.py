n = int(input())
a = list(map(int, input().split()))
rt = sum(a)
for i in range(2, n//2+1):
    if n % i == 0:
        for j in range(i):
            rt = max(rt, sum(a[j:n: n//i]))

print(rt)

