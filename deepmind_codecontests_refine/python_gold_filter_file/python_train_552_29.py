n, k = map(int, input().split())
t = [0] * n
for i in range(n):
    a, b = map(int, input().split())
    t[i] = 10 * a - b
t.sort(reverse = True)
print(t.count(t[k - 1]))