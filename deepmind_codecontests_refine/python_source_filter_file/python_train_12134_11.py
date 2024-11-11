n = int(input())
c = list(map(int, input().split()))
r = 0
x = 1
for i in range(1, n):
    if c[i] > c[i-1]:
        x += 1
    else:
        x = 1
    r = max(r, x)
print(r)
