

n, m = map(int, input().split())

if n == 0 and m == 0:
    print("0 0")
elif n == 0:
    print("Impossible")
else:
    print(str(max([m, n])) + " " + str(max([n + m - 1, n])))
