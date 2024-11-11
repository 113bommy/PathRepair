n, m = list(map(int, input().split()))
for i in range(n):
    if i%2==0:
        for j in range(m):
            print('#', end='')
    elif i%4==1:
        for j in range(m-1):
            print('.', end='')
        print('#', end='')
    elif i%4==3:
        print('#', end='')
        for j in range(m-1):
            print('.', end='')
    print('\n')