for _ in range(int(input())):
    P = int(input())
    if (P % 2 == 1):
        print(1, P - 1)
    else:
        print(2, P - 2)