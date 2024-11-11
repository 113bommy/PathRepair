n = int(input())

ct = 1
for i in range(1, n):
    ct = (ct + i) % n
    if i == n - 1:
        print(ct, end="")
    else:
        print(ct, end=" ")
