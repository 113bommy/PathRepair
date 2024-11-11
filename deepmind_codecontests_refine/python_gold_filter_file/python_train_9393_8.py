# Number of test cases.
t = int(input())

for _ in range(t):
    n = int(input())

    if n == 1:
        print(-1)
    else:
        s = "5" * (n - 1) + "8"
        print(s)