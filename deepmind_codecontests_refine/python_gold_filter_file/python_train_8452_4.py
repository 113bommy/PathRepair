for t in range(int(input())):
    n, x, a, b = [int(i) for i in input().split()]
    print(min(n-1, abs(b-a) + x))