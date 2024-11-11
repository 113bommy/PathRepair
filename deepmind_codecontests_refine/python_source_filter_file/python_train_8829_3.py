n = int(input())
a = list(map(int, input().split()))
b = [a[i] - i - 1 for i in range(n)]
median = sorted(b)[n//2-1]

res = 0
for v in b:
    res += abs(v - median)
print(res)