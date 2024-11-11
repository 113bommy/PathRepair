while True:
    y,x = [int(i) for i in input().split()]
    if y and x == 0:
        break
    for i in range(y):
        print('#'*x)
    print()