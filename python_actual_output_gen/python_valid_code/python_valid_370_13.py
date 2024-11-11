n, d = list(map(int, input().split()))
c = 0
x = 0
for i in range(d):
    if input() != '1' * n:
        c += 1
    else:
        x = max(x, c)
        c = 0
print(x)