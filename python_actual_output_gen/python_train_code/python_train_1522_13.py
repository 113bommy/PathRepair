for _ in range(int(input())):
    n = input()
    l1 = list(map(int, input().split()))
    l2 = list(map(int, input().split()))
    l1.sort()
    l2.sort()
    print(l1)
    print(l2)