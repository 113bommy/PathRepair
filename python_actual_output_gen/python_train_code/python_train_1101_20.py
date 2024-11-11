n, t = map(int, input().split())
q = -1;
for i in range(10 ** (n - 1) - 1, 10 ** (n) + 1):
    if i % t == 0:
        q = i
        break
print(q)