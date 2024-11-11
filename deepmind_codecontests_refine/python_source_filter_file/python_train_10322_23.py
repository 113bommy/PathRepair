n, l = int(input()), list(map(int, input().split()))
a, b = 0, 0
for i in range(n):
    if l[i] == 0:
        a = i
    else:
        b = i
print(min(a, b))
