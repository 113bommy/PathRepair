n, k = map(int, input().split())
candies = list(map(int, input().split()))

div = [0 for i in range(n)]

for i in candies:
    div[i % k] += 1


res = (div[0] // 2)*2
if k % 2 == 1:
    c = n//2-1
else:
    c = n//2 +1
for i in range(1, c):
    res += 2 * min(div[i], div[k - i]) if i != k - i else (div[i] // 2)*2
print(res)