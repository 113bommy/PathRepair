num = int(input())
for i in range(num):
    n, t, s = [int(s) for s in input().split()]
    double = max(t + s - n, 0)
    print(max(t - double, s - double) + 1) 