m, n = map(int, input().split())
for i in range(1, n+1):
    if i % 4 == 0:
        print('#', '.' * (m-1), sep='')
    elif i % 2 == 0:
        print('.' * (m-1), '#', sep='')
    else:
        print('#' * m, sep='')