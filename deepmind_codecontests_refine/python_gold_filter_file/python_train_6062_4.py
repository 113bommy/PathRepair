for _ in range(int(input())):
    n, m = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]
    print(min(m, sum(a)))