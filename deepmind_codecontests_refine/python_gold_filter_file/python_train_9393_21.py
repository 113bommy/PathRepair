t = int(input())

for tt in range(t):
    n = int(input())

    if n == 1:
        print(-1)
    else:
        print("9" * (n - 1) + "4")
