a, b = map(int, input().split())
print(41, 100)
for _ in range(10):
    for _ in range(50):
        print('.', end='')
        if b>1:
            print('#', end='')
            b -= 1
        else:
            print('.', end='')
    print()
    print('.'*100)
print('#'*100)
for _ in range(10):
    for _ in range(50):
        print('#', end='')
        if a>1:
            print('.', end='')
            a -= 1
        else:
            print('#', end='')
    print()
    print('#'*100)