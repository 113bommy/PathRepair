n, k = map(int, input().split())
d = list(map(int, input().split()))

divs = [0 for i in range(k)]
for i in range(n):
    divs[d[i] % k] += 1

result = divs[0] // 2

for i in range(1, (k + 1) // 2):
    result += min(divs[i], divs[k - i])

if k % 2 == 0:
    result += divs[k // 2] // 2

print(result * 2)