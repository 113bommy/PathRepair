n, k = map(int, input().split())
td = [list(map(int, input().split())) for i in range(n)]
td = sorted(td, key=lambda x: x[1], reverse=True)
sushi = [[] for i in range(2)]
used = set()
for t, d in td:
    if t in used:
        sushi[0].append(d)
    else:
        sushi[1].append(d)
        used.add(t)
y = k - min(k, len(sushi[0]))
sushi = list(reversed(sushi[0])) + sushi[1]
sum = sum(sushi[:k])
ans = sum + y ** 2
for i in range(len(sushi) - k):
    sum += sushi[k + i] - sushi[i]
    ans = max(ans, sum + (y + i + 1) ** 2)
print(ans)