# https://codeforces.com/contest/1371/problem/B

t = int(input())

for _ in range(t):
    n, r = [int(i) for i in input().split()]

    k = 1
    shapes = 0

    if (n >= r): 
        shapes = ((r + 1)*r) // 2
    else:
        # vai ate k = n - 1 e soma 1
        shapes = (n*(n-1))//2
        shapes += 1

    # para quando k = n ou quando n é maior que k
    # while (k < n and k <= r):
    #     shapes += k
    #     k += 1
    # if (k <= r):
    #     shapes += 1
    print(shapes)

    