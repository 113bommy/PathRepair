N = int(input())
ret = "seconde"
for _ in range(N):
    a = int(input())
    if a % 2 != 0:
        ret = "first"
print(ret)
