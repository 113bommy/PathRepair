for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(1 if sum(a)%n == 0 else 0)