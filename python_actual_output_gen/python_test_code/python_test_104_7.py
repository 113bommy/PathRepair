n, ans, c = int(input()), 'maybe', [99999999999999999]
for i in range(n):
    a, b = map(int, input().split())
    if a != b:
        ans = 'rated'
        break
    if a >= c[-1]:
        ans = 'unrate'
    c.append(a)
print(ans)