n, m = map(int, input().split())
for i in range(n):
    if (not i&1):
        for _ in range(m):
            print('#', end="")
    else:
        if ((i+1)%4 == 0):
            print('#', end="")
            for _ in range(1, m):
                print(".", end="")
        else:
            for _ in range(m-1):
                print(".", end="")
            print('#', end="")
    print('\n')