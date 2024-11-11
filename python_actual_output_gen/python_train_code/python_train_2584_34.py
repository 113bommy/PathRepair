n, q = map(int, input().split())
s = input()

a = [0, 0]
for i in range(2, n + 1):
    a.append(a[i - 1] + (s[i - 2:i] == 'AC'))


for _ in range(q):
    li, ri = map(int, input().split())
    print(a[ri] - a[li - 1])