a = int(input())
res = 0
while a > 0:
    if (a % 10 == 1):
        res += 1
    a //= 10
print(res)