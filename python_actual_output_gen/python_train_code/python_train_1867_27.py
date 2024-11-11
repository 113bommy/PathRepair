n = int(input())
res = 0
for i in range(n):
    if n % (i + 1) == 0:
        res = res + 1
print(res)