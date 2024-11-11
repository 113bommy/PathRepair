n, k = map(int, input().split())
if (2 * k > n * (n-1)):
    print("no solution")
else:
    for i in range(0, n):
        print("{} {}".format(0,i), flush=False)
